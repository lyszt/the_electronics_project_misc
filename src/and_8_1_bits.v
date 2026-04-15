module and_8_1_bits (
    input clk,
    input reset,
    input [7:0] bit_8,
    input bit_1,
    output reg data_out
);

  always @(posedge clk) begin 
    if (reset) begin
      data_out <= 1'b0;
    end else begin
      data_out <= bit_8 && bit_1; 
    end
  end

endmodule
