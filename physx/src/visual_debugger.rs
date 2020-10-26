// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  5 April 2019

#![warn(clippy::all)]

/*!

*/

use super::{
    foundation::Foundation,
    traits::Class,
    owner::Owner,
};

use enumflags2::BitFlags;

use physx_sys::{
    PxPvdInstrumentationFlag,
    PxPvdInstrumentationFlags,
    PxPvdSceneFlags,
    phys_PxCreatePvd,
    PxPvd_connect_mut,
    PxPvd_disconnect_mut,
    phys_PxDefaultPvdSocketTransportCreate,
    PxPvdTransport_release_mut,
    PxPvd_release_mut,
    PxPvdSceneClient_setScenePvdFlags_mut,
};

#[derive(BitFlags, Copy, Clone, Debug, PartialEq)]
#[repr(u8)]
pub enum VisualDebuggerSceneFlag {
    TransmitContacts = 1,
    TransmitSceneQueries = 2,
    TransmitConstraints = 4,
}

pub struct VisualDebugger {
    pvd: Owner<Pvd>,
    transport: Owner<PvdTransport>,
}

unsafe impl Class<physx_sys::PxPvd> for VisualDebugger {
    fn as_ptr(&self) -> *const physx_sys::PxPvd {
        self.pvd.as_ptr()
    }

    fn as_mut_ptr(&mut self) -> *mut physx_sys::PxPvd {
        self.pvd.as_mut_ptr()
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
    pub fn new(foundation: &mut Foundation, port: i32) -> Option<Self> {
        VisualDebugger::new_with_timeout(foundation, port, 10)
    }

    /// See description of `new`
    pub fn new_with_timeout(foundation: &mut Foundation, port: i32, timeout: u32) -> Option<Self> {
        use std::ffi::CStr;

        let flags = PxPvdInstrumentationFlags {
            mBits: PxPvdInstrumentationFlag::eDEBUG as u8,
        };

        let pvd = unsafe {
            Pvd::from_raw(
                phys_PxCreatePvd(foundation.as_mut_ptr())
            )?
        };
        let transport = unsafe {
            let oshost = CStr::from_bytes_with_nul_unchecked(b"localhost\0");
            PvdTransport::from_raw(
                phys_PxDefaultPvdSocketTransportCreate(oshost.as_ptr() as _, port, timeout)
            )?
        };

        let mut visual_debugger = Self { pvd, transport };
        
        visual_debugger.connect(flags);

        Some(visual_debugger)
    }

    pub fn connect(&mut self, flags: PxPvdInstrumentationFlags) -> bool {
        self.pvd.connect(self.transport.as_mut(), flags)
    }

    pub fn disconnect(&mut self) {
        self.pvd.disconnect();
    }
}

#[repr(transparent)]
pub struct PvdTransport {
    obj: physx_sys::PxPvdTransport,
}

crate::ClassObj!(PvdTransport : PxPvdTransport);

impl PvdTransport {
    pub(crate) unsafe fn from_raw<'a>(ptr: *mut physx_sys::PxPvdTransport) -> Option<Owner<PvdTransport>> {
        Owner::from_raw(ptr as *mut Self)
    }
}

unsafe impl Send for PvdTransport {}
unsafe impl Sync for PvdTransport {}

impl Drop for PvdTransport {
    fn drop(&mut self) {
        unsafe {
            PxPvdTransport_release_mut(self.as_mut_ptr());
        }
    }
}

#[repr(transparent)]
pub struct Pvd {
    obj: physx_sys::PxPvd,
}

crate::ClassObj!(Pvd : PxPvd);

impl Pvd {
    pub(crate) unsafe fn from_raw(ptr: *mut physx_sys::PxPvd) -> Option<Owner<Self>> {
        Owner::from_raw(ptr as *mut Self)
    }

    /// Connect the visual debugger over the provided transport. Returns `true`
    /// if the connection succeded.
    pub fn connect(
        &mut self,
        transport: &mut PvdTransport,
        flags: PxPvdInstrumentationFlags,
    ) -> bool {
        unsafe { PxPvd_connect_mut(self.as_mut_ptr(), transport.as_mut_ptr(), flags) }
    }

    pub fn disconnect(&mut self) {
        unsafe { PxPvd_disconnect_mut(self.as_mut_ptr()) }
    }
}

unsafe impl Send for Pvd {}
unsafe impl Sync for Pvd {}

impl Drop for Pvd {
    fn drop(&mut self) {
        unsafe {
            PxPvd_release_mut(self.as_mut_ptr());
        }
    }
}

pub struct PvdSceneClient {
    obj: physx_sys::PxPvdSceneClient,
}

crate::ClassObj!(PvdSceneClient : PxPvdSceneClient);

impl PvdSceneClient {
    #[allow(dead_code)]
    pub(crate) unsafe fn from_raw(ptr: *mut physx_sys::PxPvdSceneClient) -> Option<Owner<Self>> {
        Owner::from_raw(ptr as *mut Self)
    }

    /// Enable and disable what should be transmitted to the visual debugger
    /// instance.
    pub fn set_scene_flags(&mut self, flags: BitFlags<VisualDebuggerSceneFlag>) {
        unsafe {
            PxPvdSceneClient_setScenePvdFlags_mut(
                self.as_mut_ptr(),
                PxPvdSceneFlags {
                    mBits: flags.bits(),
                },
            )
        }
    }
}

unsafe impl Send for PvdSceneClient {}
unsafe impl Sync for PvdSceneClient {}