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

void CalculatorWindow::on_inputNum0_clicked() { assert( 0 ); }
void CalculatorWindow::on_inputNum1_clicked()
{
    ui->inputDisplay->setText( "1" );
}
void CalculatorWindow::on_inputNum2_clicked()
{
    ui->inputDisplay->setText( "2" );
}
void CalculatorWindow::on_inputNum3_clicked()
{
    ui->inputDisplay->setText( "3" );
}
void CalculatorWindow::on_inputNum4_clicked()
{
    ui->inputDisplay->setText( "4" );
}
void CalculatorWindow::on_inputNum5_clicked()
{
    ui->inputDisplay->setText( "5" );
}
void CalculatorWindow::on_inputNum6_clicked()
{
    ui->inputDisplay->setText( "6" );
}
void CalculatorWindow::on_inputNum7_clicked()
{
    ui->inputDisplay->setText( "7" );
}
void CalculatorWindow::on_inputNum8_clicked()
{
    ui->inputDisplay->setText( "8" );
}
void CalculatorWindow::on_inputNum9_clicked()
{
    ui->inputDisplay->setText( "9" );
}

void CalculatorWindow::on_inputOperDivis_clicked() {}
void CalculatorWindow::on_inputOperMinus_clicked() {}
void CalculatorWindow::on_inputOperMulti_clicked() {}
void CalculatorWindow::on_inputOperPlus_clicked() {}
