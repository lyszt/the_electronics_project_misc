module counter_8bit (
    input clk,
    input [7:0] num,
    input load,
    input reset,
    output reg [7:0] count
);

    always @(posedge clk) begin 
        if (reset) 
            count <= 8'b00000000;
        else if (load)
            count <= count;
        else
            count <= count + 1;
    end 

endmodule