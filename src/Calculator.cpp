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
        case Operation::SUBTRACT:
            firstOperand -= secondOperand;
            break;
    }
    currentOperation = Operation::NONE;
}
void Calculator::add( double operand )
{
    parseFirstOperand( operand );
    currentOperation = Operation::ADD;
}
void Calculator::subtract( double operand )
{
    parseFirstOperand( operand );
    currentOperation = Operation::SUBTRACT;
}
void Calculator::parseFirstOperand( double operand )
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
}
double Calculator::getStatus() { return firstOperand; }
