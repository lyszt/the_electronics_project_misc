module mux_8_to_1 (
    input clk,
    input reset,
    input [7:0] mux_data_in,
    output mux_data_out

);
  reg sel1_reg, sel2_reg, sel3_reg;
  wire [2:0] sel_bus;

  assign sel_bus = {sel3_reg, sel2_reg, sel1_reg};
  assign mux_data_out = mux_data_in[sel_bus];

  always @(posedge clk) begin 
    if(reset) begin 
      sel1_reg <= 1'b0;
      sel2_reg <= 1'b1;
      sel3_reg <= 1'b0;
    end
  end

endmodule
