module f1_fsm(
    input logic clk, 
    input logic rst, 
    input logic en,
    input logic trigger,
    output logic [7:0] dout,
    output logic cmd_seq,
    output logic cmd_delay
);

    typedef enum {IDLE, S1, S2, S3, S4, S5, S6, S7, S8, HOLD, OFF, DISPLAYING} state;
    //you could probably just use a counting and done state 
    //and use an internal signal which goes into the output 
    //so when youre couting you just shift and add to itself
    state cstate, nstate;

// run on pos clk or pos rst edge (asynchronous reset)
always_ff @ (posedge clk, posedge rst)
    if (rst) cstate <= IDLE;
    else cstate <= nstate;

    always_comb 
        case (cstate)
            IDLE: if (trigger) nstate = S1;
                else nstate = cstate;
            S1: if (en) nstate = S2;
                else nstate = cstate;
            S2: if (en) nstate = S3;
                else nstate = cstate;
            S3: if (en) nstate = S4;
                else nstate = cstate;
            S4: if (en) nstate = S5;
                else nstate = cstate;
            S5: if (en) nstate = S6;
                else nstate = cstate;
            S6: if (en) nstate = S7;
                else nstate = cstate;
            S7: if (en) nstate = S8;
                else nstate = cstate;
            S8: if (en) nstate = HOLD;
                else nstate = cstate;
            HOLD: if (en) nstate = OFF;
                else nstate = cstate;
            OFF: if (trigger) nstate = DISPLAYING;
                else nstate = cstate;

            DISPLAYING: nstate = IDLE;

            default: nstate = IDLE;
        endcase

    always_comb
        case (cstate)
            S1: begin
                dout = 8'b1;
                cmd_seq = 1;
            end
            S2: dout = 8'b11;
            S3: dout = 8'b111;
            S4: dout = {{4{1'b0}}, {4{1'b1}}};
            S5: dout = {{3{1'b0}}, {5{1'b1}}};
            S6: dout = {{2{1'b0}}, {6{1'b1}}};
            S7: dout = {{1'b0}, {7{1'b1}}};
            S8: dout = {8{1'b1}};
            HOLD: begin 
                dout = {8{1'b1}};
                cmd_seq = 0;
                cmd_delay = 1;
            end
            default: begin
                dout = 8'b0;
                cmd_seq = 0;
                cmd_delay = 0;
            end
        endcase
    
endmodule
