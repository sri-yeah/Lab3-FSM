module lfsr4(
    input logic clk, 
    input logic rst, 
    input logic en,
    output logic [6:0] dout //pseudo random output
);

    logic [6:0] sreg = {5'b0, 1'b1};

// run on pos clk or pos rst edge (asynchronous reset)
always_ff @ (posedge clk, posedge rst)
    if (rst) sreg <= 7'b1;
    else if (en) sreg <= {sreg[6:0], sreg[2] ^ sreg[6]};
    assign dout = sreg;
endmodule
