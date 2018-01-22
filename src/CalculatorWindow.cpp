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

CalculatorWindow::CalculatorWindow( QWidget* parent )
    : QMainWindow( parent ), ui( new Ui::CalculatorWindow )
{
    ui->setupUi( this );
}

CalculatorWindow::~CalculatorWindow() { delete ui; }
