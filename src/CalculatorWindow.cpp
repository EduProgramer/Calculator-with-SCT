/**
 * @Author: Jakub
 * @Date:   2018-01-22T15:06:36+01:00
 * @Project: Calculator with SCT
 * @Last modified by:   Jakub
 * @Last modified time: 2018-01-22T15:23:56+01:00
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

void CalculatorWindow::on_inputNum0_clicked() { assert( 0 ); }
void CalculatorWindow::on_inputNum1_clicked() {}
void CalculatorWindow::on_inputNum2_clicked() {}
void CalculatorWindow::on_inputNum3_clicked() {}
void CalculatorWindow::on_inputNum4_clicked() {}
void CalculatorWindow::on_inputNum5_clicked() {}
void CalculatorWindow::on_inputNum6_clicked() {}
void CalculatorWindow::on_inputNum7_clicked() {}
void CalculatorWindow::on_inputNum8_clicked() {}
void CalculatorWindow::on_inputNum9_clicked() {}

void CalculatorWindow::on_inputOperDivis_clicked() {}
void CalculatorWindow::on_inputOperMinus_clicked() {}
void CalculatorWindow::on_inputOperMulti_clicked() {}
void CalculatorWindow::on_inputOperPlus_clicked() {}

CalculatorWindow::~CalculatorWindow() { delete ui; }
