module counter_8bit (
    input clk,
    input [7:0] num,
    input load,
    output reg [7:0] count
);

    always @(posedge clk) begin 
        if (load)
            count <= num;
        else
            count <= count + 1;
    end 

endmodule