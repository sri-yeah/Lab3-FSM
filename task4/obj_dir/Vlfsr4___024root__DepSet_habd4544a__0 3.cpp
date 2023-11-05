// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlfsr4.h for the primary calling header

#include "verilated.h"

#include "Vlfsr4__Syms.h"
#include "Vlfsr4___024root.h"

void Vlfsr4___024root___eval_act(Vlfsr4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlfsr4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr4___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vlfsr4___024root___nba_sequent__TOP__0(Vlfsr4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlfsr4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr4___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->lfsr4__DOT__sreg = ((IData)(vlSelf->rst)
                                 ? 1U : ((0x7eU & ((IData)(vlSelf->lfsr4__DOT__sreg) 
                                                   << 1U)) 
                                         | (1U & VL_REDXOR_8(
                                                             (0x44U 
                                                              & (IData)(vlSelf->lfsr4__DOT__sreg))))));
    vlSelf->dout = vlSelf->lfsr4__DOT__sreg;
}

void Vlfsr4___024root___eval_nba(Vlfsr4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlfsr4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr4___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vlfsr4___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vlfsr4___024root___eval_triggers__act(Vlfsr4___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vlfsr4___024root___dump_triggers__act(Vlfsr4___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vlfsr4___024root___dump_triggers__nba(Vlfsr4___024root* vlSelf);
#endif  // VL_DEBUG

void Vlfsr4___024root___eval(Vlfsr4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlfsr4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr4___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vlfsr4___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vlfsr4___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("lfsr4.sv", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                Vlfsr4___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vlfsr4___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("lfsr4.sv", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vlfsr4___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vlfsr4___024root___eval_debug_assertions(Vlfsr4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlfsr4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr4___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
