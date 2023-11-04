module clktick #(
	parameter WIDTH = 16
)(
  // interface signals
  input  logic             clk,      // clock 
  input  logic             rst,      // reset
  input  logic             en,       // enable signal
  input  logic [WIDTH-1:0] N,     	 // clock divided by N+1
  output logic [7:0] dout
);

logic  tick;      // tick output
logic [WIDTH-1:0] count;

f1_fsm stateMachine (
  .clk (clk),
  .rst (rst),
  .en (tick),
  .dout (dout)
);

always_ff @ (posedge clk)
  if (rst) begin
    tick <= 1'b0;
    count <= N;  
  end
  else if (en) begin
    if (count == 0) begin
      tick <= 1'b1;
      count <= N;
    end
    else begin
      tick <= 1'b0;
      count <= count - 1'b1;
    end
  end
endmodule
