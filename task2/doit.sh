#!/bin/sh

# cleanup

rm - rf obj_dir
rm -f f1_fsm.vcd

# run Verilator to translate SystemVerilog into C++, including C++ testbench
verilator -Wall --cc --trace f1_fsm.sv --exe f1_fsm_tb.cpp

#build C++ project via make automattically generated by Verilator 
make -j -C obj_dir/ -f Vf1_fsm.mk Vf1_fsm

# run executable simulation file 
obj_dir/Vf1_fsm