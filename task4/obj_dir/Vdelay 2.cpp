// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdelay.h"
#include "Vdelay__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vdelay::Vdelay(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdelay__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , trigger{vlSymsp->TOP.trigger}
    , n{vlSymsp->TOP.n}
    , time_out{vlSymsp->TOP.time_out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdelay::Vdelay(const char* _vcname__)
    : Vdelay(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdelay::~Vdelay() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdelay___024root___eval_debug_assertions(Vdelay___024root* vlSelf);
#endif  // VL_DEBUG
void Vdelay___024root___eval_static(Vdelay___024root* vlSelf);
void Vdelay___024root___eval_initial(Vdelay___024root* vlSelf);
void Vdelay___024root___eval_settle(Vdelay___024root* vlSelf);
void Vdelay___024root___eval(Vdelay___024root* vlSelf);

void Vdelay::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdelay::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdelay___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdelay___024root___eval_static(&(vlSymsp->TOP));
        Vdelay___024root___eval_initial(&(vlSymsp->TOP));
        Vdelay___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdelay___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vdelay::eventsPending() { return false; }

uint64_t Vdelay::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vdelay::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdelay___024root___eval_final(Vdelay___024root* vlSelf);

VL_ATTR_COLD void Vdelay::final() {
    Vdelay___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdelay::hierName() const { return vlSymsp->name(); }
const char* Vdelay::modelName() const { return "Vdelay"; }
unsigned Vdelay::threads() const { return 1; }
void Vdelay::prepareClone() const { contextp()->prepareClone(); }
void Vdelay::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vdelay::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vdelay___024root__trace_init_top(Vdelay___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdelay___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdelay___024root*>(voidSelf);
    Vdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vdelay___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vdelay___024root__trace_register(Vdelay___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vdelay::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vdelay::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vdelay___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
