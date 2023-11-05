module lfsr4(
    input logic clk, 
    input logic rst, 
    output logic [6:0] dout //pseudo random output
);

    logic [6:0] sreg = {6'b0, 1'b1};

always_ff @ (posedge clk)
    if (rst) sreg <= 7'b1;
    else sreg <= {sreg[5:0], sreg[2] ^ sreg[6]};
    assign dout = sreg;
endmodule
