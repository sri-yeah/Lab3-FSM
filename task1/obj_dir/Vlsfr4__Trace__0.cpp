// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlsfr4__Syms.h"


void Vlsfr4___024root__trace_chg_sub_0(Vlsfr4___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vlsfr4___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsfr4___024root__trace_chg_top_0\n"); );
    // Init
    Vlsfr4___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlsfr4___024root*>(voidSelf);
    Vlsfr4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vlsfr4___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vlsfr4___024root__trace_chg_sub_0(Vlsfr4___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vlsfr4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsfr4___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->clk));
    bufp->chgBit(oldp+1,(vlSelf->rst));
    bufp->chgBit(oldp+2,(vlSelf->en));
    bufp->chgCData(oldp+3,(vlSelf->dout),7);
    bufp->chgCData(oldp+4,(vlSelf->lfsr4__DOT__sreg),7);
}

void Vlsfr4___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsfr4___024root__trace_cleanup\n"); );
    // Init
    Vlsfr4___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlsfr4___024root*>(voidSelf);
    Vlsfr4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}