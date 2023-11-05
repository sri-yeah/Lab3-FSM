// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vlfsr4.h for the primary calling header

#ifndef VERILATED_VLFSR4___024ROOT_H_
#define VERILATED_VLFSR4___024ROOT_H_  // guard

#include "verilated.h"


class Vlfsr4__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vlfsr4___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(dout,6,0);
    CData/*6:0*/ lfsr4__DOT__sreg;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vlfsr4__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vlfsr4___024root(Vlfsr4__Syms* symsp, const char* v__name);
    ~Vlfsr4___024root();
    VL_UNCOPYABLE(Vlfsr4___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
