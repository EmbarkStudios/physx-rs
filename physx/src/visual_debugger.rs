// Author: Tom Olsson <tom.olsson@embark-studios.com>
// Copyright © 2019, Embark Studios, all rights reserved.
// Created:  5 April 2019

#![warn(clippy::all)]

/*!

*/

use super::{foundation::Foundation, owner::Owner, traits::Class};

use enumflags2::{bitflags, BitFlags};

use physx_sys::{
    phys_PxCreatePvd, phys_PxDefaultPvdSocketTransportCreate, PxPvdInstrumentationFlag,
    PxPvdInstrumentationFlags, PxPvdSceneClient_setScenePvdFlags_mut, PxPvdSceneFlags,
    PxPvdTransport_release_mut, PxPvd_connect_mut, PxPvd_disconnect_mut, PxPvd_getTransport_mut,
    PxPvd_isConnected_mut, PxPvd_release_mut,
};

#[bitflags]
#[derive(Copy, Clone, Debug, PartialEq, Eq)]
#[repr(u8)]
pub enum VisualDebuggerSceneFlag {
    TransmitContacts = 1,
    TransmitSceneQueries = 2,
    TransmitConstraints = 4,
}

/// Combines the Pvd and it's current `PvdTransport`, if there is one.
pub struct VisualDebugger {
    pvd: Owner<Pvd>,
    transport: Option<Owner<PvdTransport>>,
    // Need to keep this field alive as the PvdTransport doesn't take ownership of the string.
    _host: std::ffi::CString,
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
    /// Create a new `VisualDebugger` instance, a utility class that
    /// combines the TCP setup and the Pvd into one object. The port
    /// default for the PVD program is port 5425, so it is suggested to use this
    /// unless you're explicitly changing the other one as well.
    ///
    /// This function internally calls `new_with_timeout` with a default timeout
    /// of 10 ms.
    pub fn new(foundation: &mut impl Foundation, port: i32) -> Option<Self> {
        VisualDebugger::new_with_timeout(foundation, "localhost", port, 10)
    }

    /// Create a new `VisualDebugger` instance, a utility class that
    /// combines the TCP setup and the Pvd into one object. The port
    /// default for the PVD program is port 5425, so it is suggested to use this
    /// unless you're explicitly changing the other one as well.
    ///
    /// This function internally calls `new_with_timeout` with a default timeout
    /// of 10 ms.
    pub fn new_remote(foundation: &mut impl Foundation, host: &str, port: i32) -> Option<Self> {
        VisualDebugger::new_with_timeout(foundation, host, port, 10)
    }

    /// See description of `new`
    pub fn new_with_timeout(
        foundation: &mut impl Foundation,
        host: &str,
        port: i32,
        timeout: u32,
    ) -> Option<Self> {
        use std::ffi::CString;

        let flags = PxPvdInstrumentationFlags {
            mBits: PxPvdInstrumentationFlag::eDEBUG as u8,
        };
        let oshost = CString::new(host).ok()?;
        let pvd = unsafe { Pvd::from_raw(phys_PxCreatePvd(foundation.as_mut_ptr()))? };
        let transport = unsafe {
            PvdTransport::from_raw(phys_PxDefaultPvdSocketTransportCreate(
                oshost.as_ptr() as _,
                port,
                timeout,
            ))
        };

        let mut visual_debugger = Self {
            pvd,
            transport,
            _host: oshost,
        };

        if !visual_debugger.connect(flags) {
            return None;
        };
        Some(visual_debugger)
    }

    /// Connect the Pvd to the `PvdTransport`.
    pub fn connect(&mut self, flags: PxPvdInstrumentationFlags) -> bool {
        if let Some(transport) = self.transport.as_mut() {
            self.pvd.connect(transport.as_mut(), flags)
        } else {
            false
        }
    }

    /// Disconnect the Pvd it's transport.
    pub fn disconnect(&mut self) {
        self.pvd.disconnect();
    }

    /// Check if the Pvd is connected.  The cached status may be up to one frame out of date.
    /// When `use_cached_status` is false, the low-level status is checked which requires locking
    /// the network stream.
    pub fn is_connected(&mut self, use_cached_status: bool) -> bool {
        self.pvd.is_connected(use_cached_status)
    }

    /// Get the transport connected to the Pvd, if there is one.
    pub fn get_transport(&mut self) -> Option<&mut PvdTransport> {
        self.pvd.get_transport()
    }

    /// Connect to a new transport, disconnecting from and dropping the old one.
    /// Returns true if the connection succeeded.
    pub fn set_transport(
        &mut self,
        transport: Owner<PvdTransport>,
        flags: PxPvdInstrumentationFlags,
    ) -> bool {
        if self.is_connected(false) {
            self.disconnect();
        };
        self.transport.replace(transport);
        self.connect(flags)
    }
}

impl Drop for VisualDebugger {
    fn drop(&mut self) {
        if self.is_connected(false) {
            self.disconnect();
        };
    }
}

#[repr(transparent)]
pub struct PvdTransport {
    obj: physx_sys::PxPvdTransport,
}

crate::DeriveClassForNewType!(PvdTransport: PxPvdTransport);

impl PvdTransport {
    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
    pub(crate) unsafe fn from_raw(
        ptr: *mut physx_sys::PxPvdTransport,
    ) -> Option<Owner<PvdTransport>> {
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

/// A new type wrapper for `PxPvd`.
#[repr(transparent)]
pub struct Pvd {
    obj: physx_sys::PxPvd,
}

crate::DeriveClassForNewType!(Pvd: PxPvd);

impl Pvd {
    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
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

    /// Disconnect from the transport.
    pub fn disconnect(&mut self) {
        unsafe { PxPvd_disconnect_mut(self.as_mut_ptr()) }
    }

    /// Check if the Pvd is connected.  The cached status may be up to one frame out of date.
    /// When `use_cached_status` is false, the low-level status is checked which requires locking
    /// the network stream.
    pub fn is_connected(&mut self, use_cached_status: bool) -> bool {
        unsafe { PxPvd_isConnected_mut(self.as_mut_ptr(), use_cached_status) }
    }

    /// Get the transport connected to the Pvd, if there is one.
    pub fn get_transport(&mut self) -> Option<&mut PvdTransport> {
        unsafe { (PxPvd_getTransport_mut(self.as_mut_ptr()) as *mut PvdTransport).as_mut() }
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

/// A new type wrapper for `PxPvdSceneClient`.
pub struct PvdSceneClient {
    obj: physx_sys::PxPvdSceneClient,
}

crate::DeriveClassForNewType!(PvdSceneClient: PxPvdSceneClient);

impl PvdSceneClient {
    /// # Safety
    /// Owner's own the pointer they wrap, using the pointer after dropping the Owner,
    /// or creating multiple Owners from the same pointer will cause UB.  Use `into_ptr` to
    /// retrieve the pointer and consume the Owner without dropping the pointee.
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
