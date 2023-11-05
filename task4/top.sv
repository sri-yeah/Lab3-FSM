module top #(
    parameter WIDTH = 16
)(
    //interface signals
    input logic clk,
    input logic rst, 
    input logic trigger,
    input logic [WIDTH-1:0] n,
    output logic [7:0] dout,
    output logic time_out
);

    logic cmd_seq;
    logic cmd_delay;
    logic mux1;
    logic mux0;
    logic muxo;
    assign muxo = (cmd_seq)?mux1:mux0;
    assign time_out = mux0;
    logic [6:0] k;

clktick clktick (
    .clk (clk),
    .rst (rst),
    .en (cmd_seq),
    .N (n),
    .tick (mux1)
);

lfsr4 lfsr (
    .clk (clk),
    .rst (rst),
    .dout (k)
);

delay delay (
    .clk (clk),
    .rst (rst),
    .trigger (cmd_delay),
    .n (k),
    .time_out (mux0)
);

f1_fsm fsm (
    .clk (clk),
    .rst (rst),
    .en (muxo),
    .trigger (trigger),
    .dout (dout),
    .cmd_seq (cmd_seq),
    .cmd_delay (cmd_delay)
);

endmodule
