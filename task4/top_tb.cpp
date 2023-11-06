#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 100000

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges
  int lights = 0; // state to toggle LED lights

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vtop * top = new Vtop;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("delay.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L3T4: F1");
  vbdSetMode(1);        // Flag mode set to one-shot

  // initialize simulation inputs
  top->clk = 1;
  top->rst = 0;
  top->trigger = 0;
  top->n = vbdValue();
  bool timing = false;
  
  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }

    // Display toggle neopixel
    vbdBar(top->dout & 0xFF);

    if(!timing && top->time_out) {
      timing = true;
      vbdInitWatch();
    }

    if(timing && top->trigger){
      timing = false;
      int timee = vbdElapsed();
      //convert to binary and then BCD and pass in with mask and int()
      vbdHex(4, (timee/1000) & 0xF);
      vbdHex(3, (timee/100) & 0xF);
      vbdHex(2, (timee/10) & 0xF);
      vbdHex(1, timee & 0xF);
    }

    // set up input signals of testbench
    top->rst = (simcyc < 2);    // assert reset for 1st cycle
    top->trigger = vbdFlag();
    top->n = vbdValue();
    vbdCycle(simcyc);

    if (Verilated::gotFinish())  exit(0);
  }

  vbdClose();     // ++++
  tfp->close(); 
  exit(0);
}
