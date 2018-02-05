#pragma once

#include <string>

enum class Operation
{
    NONE,
    ADD,
    SUBTRACT,
    DIVIDE,
    MULTIPLY
};

class Calculator
{
public:
    void calculate( double );

    void add( double );
    void subtract( double );

    double getStatus();

private:
    bool firstOperation = true;
    double firstOperand = 0.0;
    double secondOperand = 0.0;
    Operation currentOperation = Operation::NONE;

    void parseFirstOperand( double );
};
