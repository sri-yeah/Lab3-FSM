// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vclktick.h for the primary calling header

#include "verilated.h"

#include "Vclktick__Syms.h"
#include "Vclktick___024root.h"

VL_ATTR_COLD void Vclktick___024root___eval_static(Vclktick___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclktick__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclktick___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vclktick___024root___eval_initial(Vclktick___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclktick__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclktick___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = vlSelf->rst;
}

VL_ATTR_COLD void Vclktick___024root___eval_final(Vclktick___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclktick__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclktick___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vclktick___024root___eval_triggers__stl(Vclktick___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vclktick___024root___dump_triggers__stl(Vclktick___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vclktick___024root___eval_stl(Vclktick___024root* vlSelf);

VL_ATTR_COLD void Vclktick___024root___eval_settle(Vclktick___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclktick__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclktick___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vclktick___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vclktick___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("clktick.sv", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vclktick___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vclktick___024root___dump_triggers__stl(Vclktick___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclktick__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclktick___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vclktick___024root___stl_sequent__TOP__0(Vclktick___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclktick__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclktick___024root___stl_sequent__TOP__0\n"); );
    // Body
    if (((((((((0U == vlSelf->clktick__DOT__stateMachine__DOT__cstate) 
               | (1U == vlSelf->clktick__DOT__stateMachine__DOT__cstate)) 
              | (2U == vlSelf->clktick__DOT__stateMachine__DOT__cstate)) 
             | (3U == vlSelf->clktick__DOT__stateMachine__DOT__cstate)) 
            | (4U == vlSelf->clktick__DOT__stateMachine__DOT__cstate)) 
           | (5U == vlSelf->clktick__DOT__stateMachine__DOT__cstate)) 
          | (6U == vlSelf->clktick__DOT__stateMachine__DOT__cstate)) 
         | (7U == vlSelf->clktick__DOT__stateMachine__DOT__cstate))) {
        if ((0U == vlSelf->clktick__DOT__stateMachine__DOT__cstate)) {
            vlSelf->dout = 0U;
            vlSelf->clktick__DOT__stateMachine__DOT__nstate 
                = ((IData)(vlSelf->clktick__DOT__tick)
                    ? 1U : vlSelf->clktick__DOT__stateMachine__DOT__cstate);
        } else if ((1U == vlSelf->clktick__DOT__stateMachine__DOT__cstate)) {
            vlSelf->dout = 1U;
            vlSelf->clktick__DOT__stateMachine__DOT__nstate 
                = ((IData)(vlSelf->clktick__DOT__tick)
                    ? 2U : vlSelf->clktick__DOT__stateMachine__DOT__cstate);
        } else if ((2U == vlSelf->clktick__DOT__stateMachine__DOT__cstate)) {
            vlSelf->dout = 3U;
            vlSelf->clktick__DOT__stateMachine__DOT__nstate 
                = ((IData)(vlSelf->clktick__DOT__tick)
                    ? 3U : vlSelf->clktick__DOT__stateMachine__DOT__cstate);
        } else if ((3U == vlSelf->clktick__DOT__stateMachine__DOT__cstate)) {
            vlSelf->dout = 7U;
            vlSelf->clktick__DOT__stateMachine__DOT__nstate 
                = ((IData)(vlSelf->clktick__DOT__tick)
                    ? 4U : vlSelf->clktick__DOT__stateMachine__DOT__cstate);
        } else if ((4U == vlSelf->clktick__DOT__stateMachine__DOT__cstate)) {
            vlSelf->dout = 0xfU;
            vlSelf->clktick__DOT__stateMachine__DOT__nstate 
                = ((IData)(vlSelf->clktick__DOT__tick)
                    ? 5U : vlSelf->clktick__DOT__stateMachine__DOT__cstate);
        } else if ((5U == vlSelf->clktick__DOT__stateMachine__DOT__cstate)) {
            vlSelf->dout = 0x1fU;
            vlSelf->clktick__DOT__stateMachine__DOT__nstate 
                = ((IData)(vlSelf->clktick__DOT__tick)
                    ? 6U : vlSelf->clktick__DOT__stateMachine__DOT__cstate);
        } else if ((6U == vlSelf->clktick__DOT__stateMachine__DOT__cstate)) {
            vlSelf->dout = 0x3fU;
            vlSelf->clktick__DOT__stateMachine__DOT__nstate 
                = ((IData)(vlSelf->clktick__DOT__tick)
                    ? 7U : vlSelf->clktick__DOT__stateMachine__DOT__cstate);
        } else {
            vlSelf->dout = 0x7fU;
            vlSelf->clktick__DOT__stateMachine__DOT__nstate 
                = ((IData)(vlSelf->clktick__DOT__tick)
                    ? 8U : vlSelf->clktick__DOT__stateMachine__DOT__cstate);
        }
    } else if ((8U == vlSelf->clktick__DOT__stateMachine__DOT__cstate)) {
        vlSelf->dout = 0xffU;
        vlSelf->clktick__DOT__stateMachine__DOT__nstate 
            = ((IData)(vlSelf->clktick__DOT__tick) ? 0U
                : vlSelf->clktick__DOT__stateMachine__DOT__cstate);
    } else {
        vlSelf->dout = 0U;
        vlSelf->clktick__DOT__stateMachine__DOT__nstate = 0U;
    }
}

VL_ATTR_COLD void Vclktick___024root___eval_stl(Vclktick___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclktick__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclktick___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vclktick___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vclktick___024root___dump_triggers__act(Vclktick___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclktick__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclktick___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vclktick___024root___dump_triggers__nba(Vclktick___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclktick__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclktick___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vclktick___024root___ctor_var_reset(Vclktick___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclktick__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclktick___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->en = VL_RAND_RESET_I(1);
    vlSelf->N = VL_RAND_RESET_I(16);
    vlSelf->dout = VL_RAND_RESET_I(8);
    vlSelf->clktick__DOT__tick = VL_RAND_RESET_I(1);
    vlSelf->clktick__DOT__count = VL_RAND_RESET_I(16);
    vlSelf->clktick__DOT__stateMachine__DOT__cstate = 0;
    vlSelf->clktick__DOT__stateMachine__DOT__nstate = 0;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_RAND_RESET_I(1);
}
