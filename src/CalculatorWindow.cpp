/**
 * @Author: jakub
 * @Project: Calculator with SCT
 * @License: MIT
 */


#include "CalculatorWindow.hpp"
#include "ui_CalculatorWindow.h"
#include <cassert>

CalculatorWindow::CalculatorWindow( QWidget* parent )
    : QMainWindow( parent ), ui( new Ui::CalculatorWindow )
{
    ui->setupUi( this );
}

CalculatorWindow::~CalculatorWindow() { delete ui; }

std::string CalculatorWindow::getScreenState()
{
    std::string screenState = ui->inputDisplay->text().toStdString();
    return screenState;
}

void CalculatorWindow::on_inputNum0_clicked() { addDigitToNumBuffor( L'0' ); }
void CalculatorWindow::on_inputNum1_clicked() { addDigitToNumBuffor( L'1' ); }
void CalculatorWindow::on_inputNum2_clicked() { addDigitToNumBuffor( L'2' ); }
void CalculatorWindow::on_inputNum3_clicked() { addDigitToNumBuffor( L'3' ); }
void CalculatorWindow::on_inputNum4_clicked() { addDigitToNumBuffor( L'4' ); }
void CalculatorWindow::on_inputNum5_clicked() { addDigitToNumBuffor( L'5' ); }
void CalculatorWindow::on_inputNum6_clicked() { addDigitToNumBuffor( L'6' ); }
void CalculatorWindow::on_inputNum7_clicked() { addDigitToNumBuffor( L'7' ); }
void CalculatorWindow::on_inputNum8_clicked() { addDigitToNumBuffor( L'8' ); }
void CalculatorWindow::on_inputNum9_clicked() { addDigitToNumBuffor( L'9' ); }

void CalculatorWindow::on_inputOperDivis_clicked()
{
    calc.divide( numBuffor.toDouble() );
    numBuffor.clear();
    updateScreen();
}
void CalculatorWindow::on_inputOperMinus_clicked()
{
    calc.subtract( numBuffor.toDouble() );
    numBuffor.clear();
    updateScreen();
}
void CalculatorWindow::on_inputOperMulti_clicked()
{
    calc.multiply( numBuffor.toDouble() );
    numBuffor.clear();
    updateScreen();
}
void CalculatorWindow::on_inputOperPlus_clicked()
{
    calc.add( numBuffor.toDouble() );
    numBuffor.clear();
    updateScreen();
}

void CalculatorWindow::on_inputOperResult_clicked()
{
    calc.calculate( numBuffor.toDouble() );
    numBuffor = QString::number( calc.getStatus() );
    updateScreen();
}

void CalculatorWindow::updateScreen()
{
    ui->inputDisplay->setText( numBuffor );
}

void CalculatorWindow::addDigitToNumBuffor( QChar digit )
{
    if ( numBuffor.isEmpty() )
    {
        if ( digit == L'0' )
        {
            return;
        }
    }
    numBuffor += digit;
    updateScreen();
}
