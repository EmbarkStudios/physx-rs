// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  5 April 2019

#![warn(clippy::all)]

/*!

*/

use super::{foundation::*, px_type::*, traits::*};
use enumflags2::BitFlags;
use log::*;
use physx_macros::*;
use physx_sys::*;

#[derive(BitFlags, Copy, Clone, Debug, PartialEq)]
#[repr(u8)]
pub enum VisualDebuggerSceneFlag {
    TransmitContacts = 1,
    TransmitSceneQueries = 2,
    TransmitConstraints = 4,
}

pub struct VisualDebugger {
    pvd: Pvd,
    transport: *mut PxPvdTransport,
}

#[physx_type]
impl Pvd {
    /// Construct a new Pvd instance tied to the Foundation object
    fn new(foundation: &mut Foundation) -> Self {
        let self_raw = unsafe { phys_PxCreatePvd(foundation.get_raw_mut()) };
        Self::from_ptr(self_raw)
    }

    /// Connect the visual debugger over the provided transport. Returns `true`
    /// if the connection succeded.
    fn connect(
        &mut self,
        transport: *mut PxPvdTransport,
        flags: PxPvdInstrumentationFlags,
    ) -> bool {
        unsafe { PxPvd_connect_mut(self.get_raw_mut(), transport, flags) }
    }
}

#[physx_type]
impl PvdSceneClient {
    /// Enable and disable what should be transmitted to the visual debugger
    /// instance.
    pub fn set_scene_flags(&mut self, flags: BitFlags<VisualDebuggerSceneFlag>) {
        unsafe {
            PxPvdSceneClient_setScenePvdFlags_mut(
                self.ptr,
                PxPvdSceneFlags {
                    mBits: flags.bits(),
                },
            )
        }
    }
}

impl VisualDebugger {
    /// Create a new VisualDebugger instance. This is a utility class that
    /// combines the TCP setup and the actual Pvd into one object. The port
    /// default for the PVD program is port 5425, so it is suggested to use this
    /// unless you're explicitly changing the other one as well.
    ///
    /// This function internally calls `new_with_timeout` with a default timeout
    /// of 10 ms.
    pub fn new(foundation: &mut Foundation, port: i32) -> Self {
        VisualDebugger::new_with_timeout(foundation, port, 10)
    }

    /// See description of `new`
    pub fn new_with_timeout(foundation: &mut Foundation, port: i32, timeout: u32) -> Self {
        use std::ffi::CStr;

        let flags = PxPvdInstrumentationFlags {
            mBits: PxPvdInstrumentationFlag::eDEBUG as u8,
        };

        let mut pvd = Pvd::new(foundation);
        let transport = unsafe {
            let oshost = CStr::from_bytes_with_nul_unchecked(b"localhost\0");
            phys_PxDefaultPvdSocketTransportCreate(oshost.as_ptr() as _, port, timeout)
        };

        if !pvd.connect(transport, flags) {
            warn!("failed connecting visual debugger, running in no-debug mode");
        }

        Self { pvd, transport }
    }

    /// Get a const pointer to the underlying PhysX object
    pub fn get_raw(&self) -> *const PxPvd {
        self.pvd.get_raw()
    }

    /// Get a mut pointer to the underlying PhysX object
    pub fn get_raw_mut(&mut self) -> *mut PxPvd {
        self.pvd.get_raw_mut()
    }
}

impl Releasable for Pvd {
    /// Release the Pvd object, invalidating it
    fn release(&mut self) {
        unsafe {
            PxPvd_release_mut(self.get_raw_mut());
        }
    }
}

impl Drop for VisualDebugger {
    /// Release the Pvd object, invalidating it
    fn drop(&mut self) {
        unsafe {
            self.pvd.release();
            PxPvdTransport_release_mut(self.transport);
        }
    }
}
