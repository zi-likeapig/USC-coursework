#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <utility>
#include <vector>

// Enum representing different arithmetic operations
enum class Operation {
  kAdd,           // Addition
  kSubtract,      // Subtraction
  kDivision,      // Division
  kMultiplication // Multiplication
};

// Enum representing possible error codes
enum class ErrorCode {
  kNoError,        // No error
  kDivisionByZero, // Error due to division by zero
  kInvalidIndex    // Error due to invalid index for history retrieval
};

// Struct representing a single calculation record
struct CalculationRecord {
  int op1;             // First operand
  int op2;             // Second operand
  Operation operation; // Operation performed
  float result;        // Result of the calculation returned
};

//-----------------------------------------------------------------------------
// TODO: Implement the member functions of this class in q.cc file.
// DO NOT MODIFY THIS FILE.
//-----------------------------------------------------------------------------
// Class representing a calculator with history functionality
class Calculator {
public:
  // Default constructor initializes the calculator
  Calculator();

  // Copy constructor creates a copy of another calculator instance
  Calculator(const Calculator &other);

  // Performs a calculation given two integers and an operation
  // Sets error_code to kDivisionByZero and returns 0 if a division by zero occurs
  float Calculate(int a, int b, Operation operation);

  // Overloaded Calculate method that uses the result of the last calculation
  // If there is no previous result, the first operand defaults to 0
  float Calculate(int a, Operation operation);

  // Retrieves a specific calculation record from the history
  // Sets error_code to kInvalidIndex if the provided index is out of range 
  // and returns a record where the operation is kAdd with other values being zeros.
  // History(0) returns the most recent calculation record.
  // History(1) returns one before the most recent calculation record.
  CalculationRecord History(int index);

  // Error code indicating the status of the calculator
  ErrorCode error_code = ErrorCode::kNoError;

private:
  // Vector storing the history of calculations.
  // It should always be updated for each calculation
  // even when it's failed (kDivisionByZero).
  std::vector<CalculationRecord> history;
};

#endif // CALCULATOR_H
