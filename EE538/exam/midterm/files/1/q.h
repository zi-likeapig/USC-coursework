#include <iostream>
#include <string>

// Function to evaluate expressions consisting of decimal 0s and 1s, with '+'
// and '-' operators. Spaces in the expression are ignored. The '+' or '-' can
// be the first character in the expression. The function assumes the input is
// always valid. Returns the result of the expression as an integer.
// Example: input: 1+1+1-1, output : 2
// Example: input: -1+1, output : 0
int evaluateExpression(const std::string &expr);