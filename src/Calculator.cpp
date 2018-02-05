#include "Calculator.hpp"

void Calculator::calculate( double secondOperand )
{
    switch ( currentOperation )
    {
        case Operation::NONE:
            break;
        case Operation::ADD:
            firstOperand += secondOperand;
            break;
    }
    currentOperation = Operation::NONE;
}
void Calculator::add( double operand )
{
    if ( firstOperation )
    {
        this->firstOperand = operand;
        firstOperation = false;
    }
    else
    {
        this->secondOperand = operand;
    }
    currentOperation = Operation::ADD;
}
double Calculator::getStatus() { return firstOperand; }
