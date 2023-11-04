module f1_fsm(
    input logic clk, 
    input logic rst, 
    input logic en,
    output logic [7:0] dout 
);

    typedef enum {IDLE, S1, S2, S3, S4, S5, S6, S7, S8} state;
    state cstate, nstate;

// run on pos clk or pos rst edge (asynchronous reset)
always_ff @ (posedge clk, posedge rst)
    if (rst) cstate <= IDLE;
    else cstate <= nstate;

        always_comb 
            case (cstate)
                IDLE: if (en) nstate = S1;
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
                S8: if (en) nstate = IDLE;
                    else nstate = cstate;
                default: nstate = IDLE;
            endcase

    always_comb
        case (cstate)
            IDLE: dout = 8'b0;
            S1: dout = 8'b1;
            S2: dout = 8'b11;
            S3: dout = 8'b111;
            S4: dout = {4{1'b1}};
            S5: dout = {5{1'b1}};
            S6: dout = {6{1'b1}};
            S7: dout = {7{1'b1}};
            S8: dout = {8{1'b1}};
            default: dout = 8'b0;
        endcase
    
endmodule
