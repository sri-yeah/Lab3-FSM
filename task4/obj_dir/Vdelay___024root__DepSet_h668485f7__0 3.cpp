// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdelay.h for the primary calling header

#include "verilated.h"

#include "Vdelay__Syms.h"
#include "Vdelay___024root.h"

VL_INLINE_OPT void Vdelay___024root___ico_sequent__TOP__0(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___ico_sequent__TOP__0\n"); );
    // Body
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

void Vdelay___024root___eval_ico(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vdelay___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vdelay___024root___eval_act(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vdelay___024root___nba_sequent__TOP__0(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->delay__DOT__count = (0x7fU & ((((IData)(vlSelf->rst) 
                                            | (IData)(vlSelf->trigger)) 
                                           | (0U == (IData)(vlSelf->delay__DOT__count)))
                                           ? ((IData)(vlSelf->n) 
                                              - (IData)(1U))
                                           : ((IData)(vlSelf->delay__DOT__count) 
                                              - (IData)(1U))));
    vlSelf->delay__DOT__current_state = ((IData)(vlSelf->rst)
                                          ? 0U : vlSelf->delay__DOT__next_state);
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

void Vdelay___024root___eval_nba(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vdelay___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vdelay___024root___eval_triggers__ico(Vdelay___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdelay___024root___dump_triggers__ico(Vdelay___024root* vlSelf);
#endif  // VL_DEBUG
void Vdelay___024root___eval_triggers__act(Vdelay___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdelay___024root___dump_triggers__act(Vdelay___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdelay___024root___dump_triggers__nba(Vdelay___024root* vlSelf);
#endif  // VL_DEBUG

void Vdelay___024root___eval(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vdelay___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vdelay___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("delay.sv", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vdelay___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vdelay___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vdelay___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("delay.sv", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                Vdelay___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vdelay___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("delay.sv", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vdelay___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vdelay___024root___eval_debug_assertions(Vdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdelay___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->trigger & 0xfeU))) {
        Verilated::overWidthError("trigger");}
    if (VL_UNLIKELY((vlSelf->n & 0x80U))) {
        Verilated::overWidthError("n");}
}
#endif  // VL_DEBUG
