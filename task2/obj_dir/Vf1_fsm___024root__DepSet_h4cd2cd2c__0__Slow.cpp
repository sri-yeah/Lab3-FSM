// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vf1_fsm.h for the primary calling header

#include "verilated.h"

#include "Vf1_fsm__Syms.h"
#include "Vf1_fsm__Syms.h"
#include "Vf1_fsm___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vf1_fsm___024root___dump_triggers__stl(Vf1_fsm___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vf1_fsm___024root___eval_triggers__stl(Vf1_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vf1_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vf1_fsm___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (0U == vlSelf->__VstlIterCount));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vf1_fsm___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
