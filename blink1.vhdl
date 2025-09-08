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

//////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////// BCD_to_7seg.v ////////////////////////////////////////////////////////

module bcd_to_7seg (
    input [3:0] bcd_in,
    output reg [6:0] seg_out
);

always @(*) begin
    case (bcd_in)
        4'b0000: seg_out = 7'b0000001; // Digit 0
        4'b0001: seg_out = 7'b1001111; // Digit 1
        4'b0010: seg_out = 7'b0010010; // Digit 2
        4'b0011: seg_out = 7'b0000110; // Digit 3
        4'b0100: seg_out = 7'b1001100; // Digit 4
        4'b0101: seg_out = 7'b0100100; // Digit 5
        4'b0110: seg_out = 7'b0100000; // Digit 6
        4'b0111: seg_out = 7'b0001111; // Digit 7
        4'b1000: seg_out = 7'b0000000; // Digit 8
        4'b1001: seg_out = 7'b0000100; // Digit 9
        default: seg_out = 7'b1111111; // All off for invalid BCD (10-15)
    endcase
end

endmodule

//////////////////////////////////////////////////////////////////////////////////////////////////
