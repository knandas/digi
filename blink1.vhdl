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


////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// slower_clock.v //////////////////////////////////////////////////////
    
module slower_clock(input clk, output reg clkOutput);

reg [22:0] counter;

always @(posedge clk) 
    if(counter==5000000) counter <= 0; else counter <= counter+1;

always @(posedge clk) 
    if(counter==5000000) 
        begin
            clkOutput <= ~clkOutput;
        end
endmodule

/////////////////////////////
