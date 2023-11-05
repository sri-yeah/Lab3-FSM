// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vlfsr4.h"
#include "Vlfsr4__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vlfsr4::Vlfsr4(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vlfsr4__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , dout{vlSymsp->TOP.dout}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vlfsr4::Vlfsr4(const char* _vcname__)
    : Vlfsr4(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vlfsr4::~Vlfsr4() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vlfsr4___024root___eval_debug_assertions(Vlfsr4___024root* vlSelf);
#endif  // VL_DEBUG
void Vlfsr4___024root___eval_static(Vlfsr4___024root* vlSelf);
void Vlfsr4___024root___eval_initial(Vlfsr4___024root* vlSelf);
void Vlfsr4___024root___eval_settle(Vlfsr4___024root* vlSelf);
void Vlfsr4___024root___eval(Vlfsr4___024root* vlSelf);

void Vlfsr4::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vlfsr4::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vlfsr4___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vlfsr4___024root___eval_static(&(vlSymsp->TOP));
        Vlfsr4___024root___eval_initial(&(vlSymsp->TOP));
        Vlfsr4___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vlfsr4___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vlfsr4::eventsPending() { return false; }

uint64_t Vlfsr4::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vlfsr4::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vlfsr4___024root___eval_final(Vlfsr4___024root* vlSelf);

VL_ATTR_COLD void Vlfsr4::final() {
    Vlfsr4___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vlfsr4::hierName() const { return vlSymsp->name(); }
const char* Vlfsr4::modelName() const { return "Vlfsr4"; }
unsigned Vlfsr4::threads() const { return 1; }
void Vlfsr4::prepareClone() const { contextp()->prepareClone(); }
void Vlfsr4::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vlfsr4::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vlfsr4___024root__trace_init_top(Vlfsr4___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vlfsr4___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlfsr4___024root*>(voidSelf);
    Vlfsr4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vlfsr4___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vlfsr4___024root__trace_register(Vlfsr4___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vlfsr4::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vlfsr4::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vlfsr4___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
