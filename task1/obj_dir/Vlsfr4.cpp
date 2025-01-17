// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vlsfr4.h"
#include "Vlsfr4__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vlsfr4::Vlsfr4(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vlsfr4__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , en{vlSymsp->TOP.en}
    , dout{vlSymsp->TOP.dout}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vlsfr4::Vlsfr4(const char* _vcname__)
    : Vlsfr4(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vlsfr4::~Vlsfr4() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vlsfr4___024root___eval_debug_assertions(Vlsfr4___024root* vlSelf);
#endif  // VL_DEBUG
void Vlsfr4___024root___eval_static(Vlsfr4___024root* vlSelf);
void Vlsfr4___024root___eval_initial(Vlsfr4___024root* vlSelf);
void Vlsfr4___024root___eval_settle(Vlsfr4___024root* vlSelf);
void Vlsfr4___024root___eval(Vlsfr4___024root* vlSelf);

void Vlsfr4::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vlsfr4::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vlsfr4___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vlsfr4___024root___eval_static(&(vlSymsp->TOP));
        Vlsfr4___024root___eval_initial(&(vlSymsp->TOP));
        Vlsfr4___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vlsfr4___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vlsfr4::eventsPending() { return false; }

uint64_t Vlsfr4::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vlsfr4::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vlsfr4___024root___eval_final(Vlsfr4___024root* vlSelf);

VL_ATTR_COLD void Vlsfr4::final() {
    Vlsfr4___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vlsfr4::hierName() const { return vlSymsp->name(); }
const char* Vlsfr4::modelName() const { return "Vlsfr4"; }
unsigned Vlsfr4::threads() const { return 1; }
void Vlsfr4::prepareClone() const { contextp()->prepareClone(); }
void Vlsfr4::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vlsfr4::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vlsfr4___024root__trace_init_top(Vlsfr4___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vlsfr4___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlsfr4___024root*>(voidSelf);
    Vlsfr4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vlsfr4___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vlsfr4___024root__trace_register(Vlsfr4___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vlsfr4::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vlsfr4::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vlsfr4___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
