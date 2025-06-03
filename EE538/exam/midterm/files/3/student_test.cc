#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Writing student test is optional!
//-----------------------------------------------------------------------------

TEST(Calculator, test1) {
    Calculator calc;    //default
    EXPECT_EQ(calc.error_code, ErrorCode::kNoError);

    // 1
    float result = calc.Calculate(2, 3, Operation::kAdd);
    EXPECT_FLOAT_EQ(result, 5.0);

    // 2
    result = calc.Calculate(10, 4, Operation::kSubtract);
    EXPECT_FLOAT_EQ(result, 6.0);

    // 3
    result = calc.Calculate(3, 3, Operation::kMultiplication);
    EXPECT_FLOAT_EQ(result, 9.0);

    // 4 (divide to integer)
    result = calc.Calculate(10, 2, Operation::kDivision);
    EXPECT_FLOAT_EQ(result, 5.0);

    // 5 (divide to float)
    result = calc.Calculate(3, 2, Operation::kDivision);
    EXPECT_FLOAT_EQ(result, 1.5);

    // 6 (devide by 0)
    result = calc.Calculate(10, 0, Operation::kDivision);
    EXPECT_FLOAT_EQ(result, 0.0);
    EXPECT_EQ(calc.error_code, ErrorCode::kDivisionByZero);

    // 7
    result = calc.Calculate(5, 5, Operation::kAdd);
    EXPECT_FLOAT_EQ(result, 10.0);

    // check history (valid 0)
    CalculationRecord record = calc.History(0);
    EXPECT_EQ(record.op1, 5);
    EXPECT_FLOAT_EQ(record.op2, 5.0);
    EXPECT_EQ(record.operation, Operation::kAdd);
    EXPECT_FLOAT_EQ(record.result, 10.0);

    // check history (valid 2)
    record = calc.History(2);
    EXPECT_EQ(record.op1, 3);
    EXPECT_FLOAT_EQ(record.op2, 2.0);
    EXPECT_EQ(record.operation, Operation::kDivision);
    EXPECT_FLOAT_EQ(record.result, 1.5);

    // check history (invalid )
    record = calc.History(10);
    EXPECT_EQ(calc.error_code, ErrorCode::kInvalidIndex);
    EXPECT_EQ(record.op1, 0);
    EXPECT_FLOAT_EQ(record.op2, 0);
    EXPECT_EQ(record.operation, Operation::kAdd);
    EXPECT_FLOAT_EQ(record.result, 0.0);

}


TEST(Calculator, test2) {
    Calculator calc;    //default
    EXPECT_EQ(calc.error_code, ErrorCode::kNoError);

    // 1
    float result = calc.Calculate(2, 5, Operation::kAdd);
    EXPECT_FLOAT_EQ(result, 7.0);

    // 2 (overload valid)
    result = calc.Calculate(10, Operation::kSubtract);
    EXPECT_FLOAT_EQ(result, 3.0);

    // check history (valid 0)
    CalculationRecord record = calc.History(0);
    EXPECT_EQ(record.op1, 10);
    EXPECT_FLOAT_EQ(record.op2, 7.0);
    EXPECT_EQ(record.operation, Operation::kSubtract);
    EXPECT_FLOAT_EQ(record.result, 3.0);

    // 3 (devide by 0)
    result = calc.Calculate(10, 0, Operation::kDivision);
    EXPECT_FLOAT_EQ(result, 0.0);
    EXPECT_EQ(calc.error_code, ErrorCode::kDivisionByZero);

    // 4 (overload invalid)
    result = calc.Calculate(10, Operation::kDivision);
    EXPECT_FLOAT_EQ(result, 0.0);
    EXPECT_EQ(calc.error_code, ErrorCode::kDivisionByZero);

    // check history (valid 0)
    record = calc.History(0);
    EXPECT_EQ(record.op1, 10);
    EXPECT_FLOAT_EQ(record.op2, 0.0);
    EXPECT_EQ(record.operation, Operation::kDivision);
    EXPECT_FLOAT_EQ(record.result, 0.0);
}


TEST(Calculator, copy1) {
    Calculator calc;    //default

    // 
    float result = calc.Calculate(2, 5, Operation::kAdd);
    EXPECT_FLOAT_EQ(result, 7.0);

    // copy (kNoError)
    Calculator calc_ = calc;
    EXPECT_FLOAT_EQ(calc_.History(0).result, 7.0);
    EXPECT_EQ(calc_.error_code, ErrorCode::kNoError);

    // devide by 0
    result = calc.Calculate(10, 0, Operation::kDivision);
    EXPECT_FLOAT_EQ(result, 0.0);
    EXPECT_EQ(calc.error_code, ErrorCode::kDivisionByZero);

    // copy (kDivisionByZero)
    calc_ = calc;
    EXPECT_EQ(calc_.error_code, ErrorCode::kDivisionByZero);
    EXPECT_FLOAT_EQ(calc_.History(0).result, 0.0);

    // check history (invalid)
    CalculationRecord record = calc.History(5);
    EXPECT_EQ(record.op1, 0);
    EXPECT_FLOAT_EQ(record.op2, 0.0);
    EXPECT_EQ(record.operation, Operation::kAdd);
    EXPECT_FLOAT_EQ(record.result, 0.0);

    // copy (kInvalidIndex)
    calc_ = calc;
    EXPECT_EQ(calc_.error_code, ErrorCode::kInvalidIndex);
    EXPECT_FLOAT_EQ(calc_.History(0).result, 0.0);
}