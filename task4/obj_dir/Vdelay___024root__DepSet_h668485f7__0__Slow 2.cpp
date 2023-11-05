// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdelay.h for the primary calling header

#include "verilated.h"

#include "Vdelay__Syms.h"
#include "Vdelay___024root.h"

VL_ATTR_COLD void Vdelay___024root___eval_static__TOP(Vdelay___024root* vlSelf);

VL_ATTR_COLD void Vdelay___024root___eval_static(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___eval_static\n"); );
    // Body
    Vdelay___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vdelay___024root___eval_static__TOP(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->delay__DOT__count = 0U;
}

VL_ATTR_COLD void Vdelay___024root___eval_initial(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vdelay___024root___eval_final(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vdelay___024root___eval_triggers__stl(Vdelay___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdelay___024root___dump_triggers__stl(Vdelay___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vdelay___024root___eval_stl(Vdelay___024root* vlSelf);

VL_ATTR_COLD void Vdelay___024root___eval_settle(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vdelay___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vdelay___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("delay.sv", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vdelay___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdelay___024root___dump_triggers__stl(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdelay___024root___stl_sequent__TOP__0(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->time_out = ((0U != vlSelf->delay__DOT__current_state) 
                        & ((1U != vlSelf->delay__DOT__current_state) 
                           & (2U == vlSelf->delay__DOT__current_state)));
    vlSelf->delay__DOT__next_state = ((0U == vlSelf->delay__DOT__current_state)
                                       ? ((IData)(vlSelf->trigger)
                                           ? 1U : vlSelf->delay__DOT__current_state)
                                       : ((1U == vlSelf->delay__DOT__current_state)
                                           ? ((0U == (IData)(vlSelf->delay__DOT__count))
                                               ? 2U
                                               : vlSelf->delay__DOT__current_state)
                                           : ((2U == vlSelf->delay__DOT__current_state)
                                               ? ((IData)(vlSelf->trigger)
                                                   ? 3U
                                                   : 0U)
                                               : ((3U 
                                                   == vlSelf->delay__DOT__current_state)
                                                   ? 
                                                  ((IData)(vlSelf->trigger)
                                                    ? vlSelf->delay__DOT__current_state
                                                    : 0U)
                                                   : 0U))));
}

VL_ATTR_COLD void Vdelay___024root___eval_stl(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vdelay___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdelay___024root___dump_triggers__ico(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdelay___024root___dump_triggers__act(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdelay___024root___dump_triggers__nba(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdelay___024root___ctor_var_reset(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->trigger = VL_RAND_RESET_I(1);
    vlSelf->n = VL_RAND_RESET_I(7);
    vlSelf->time_out = VL_RAND_RESET_I(1);
    vlSelf->delay__DOT__count = VL_RAND_RESET_I(7);
    vlSelf->delay__DOT__current_state = 0;
    vlSelf->delay__DOT__next_state = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
}
