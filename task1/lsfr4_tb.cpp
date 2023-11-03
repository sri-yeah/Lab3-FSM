#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vlsfr4.h"

#include "vbuddy.cpp"
#define MAX_SIM_CYC 1000000

int main(int argc, char **argv, char **env) {
    int simcyc;
    int tick;

    Verilated::commandArgs(argc, argv);
    // init top verilog instance 
    Vlsfr4* top = new Vlsfr4;
    // innit trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99); 
    tfp->open ("lsf4.vcd");
    
    // init vbuddy
    if (vbdOpen()!=1) return(-1);
    vbdHeader("L3T1:4bit LSFR");
    vbdSetMode(1);

    // initialise simulation input
    top->clk = 1;
    top->rst = 0;
    top->en = 1;


    //run simulations 
    for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
        for (tick=0; tick<2; tick++) {
            tfp->dump (2*simcyc+tick);
            top->clk = !top->clk;
            top->eval ();
        }

        //do stuff
        //top->en = vbdFlag();

        //display stuff
        vbdHex(2, (top->dout >> 4) & 0xF);
        vbdHex(1, top->dout & 0xF);
        vbdBar(top->dout & 0xFF);

        // either sim finished or 'q' is pressed
        if (Verilated::gotFinish() || vbdGetkey() == 'q')
            exit(0);
    }

    vbdClose();
    tfp->close();
    printf("Exiting\n");
    exit(0);
}