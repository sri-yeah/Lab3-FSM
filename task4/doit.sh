#!/bin/sh

# cleanup
rm -rf obj_dir
rm -f top.vcd
rm -f delay.vcd
rm -f f1_fsm.vcd
rm -f clktick.vcd
rm -f lfsr4.vcd

# run Verilator to translate Verilog into C++, including C++ testbench
verilator -Wall --cc --trace top.sv --exe top_tb.cpp
verilator -Wall --cc --trace delay.sv --exe top_tb.cpp
verilator -Wall --cc --trace f1_fsm.sv --exe top_tb.cpp
verilator -Wall --cc --trace clktick.sv --exe top_tb.cpp
verilator -Wall --cc --trace lfsr4.sv --exe top_tb.cpp

# build C++ project via make automatically generated by Verilator
make -j -C obj_dir/ -f Vtop.mk Vtop

# run executable simulation file
echo "\nRunning simulation"
obj_dir/Vtop
echo "\nSimulation completed"

