module counter(clk, out);
  input clk;
  output out;

  reg out;

  reg[23:0] count;

  always @(posedge clk) begin 
     count <= count + 1'b1; 
     out <= count[23];
  end
endmodule    
