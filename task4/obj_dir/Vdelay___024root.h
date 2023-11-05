// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdelay.h for the primary calling header

#ifndef VERILATED_VDELAY___024ROOT_H_
#define VERILATED_VDELAY___024ROOT_H_  // guard

#include "verilated.h"


class Vdelay__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdelay___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(trigger,0,0);
    VL_IN8(n,6,0);
    VL_OUT8(time_out,0,0);
    CData/*6:0*/ delay__DOT__count;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ delay__DOT__current_state;
    IData/*31:0*/ delay__DOT__next_state;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdelay__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdelay___024root(Vdelay__Syms* symsp, const char* v__name);
    ~Vdelay___024root();
    VL_UNCOPYABLE(Vdelay___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
