module adder_8bit ( 
    input [7: 0] a,
    input [7: 0] b,
    input cin, 
    output [7: 0] sum, 
    output cout
);
    // The ^ operator is XOR, & is AND, | is OR
    assign {cout, sum} = a + b + cin;

endmodule