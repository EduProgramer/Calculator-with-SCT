/**
 * @Author: Jakub
 * @Date:   2018-01-22T15:06:40+01:00
 * @Project: Calculator with SCT
 * @Last modified by:   Jakub
 * @Last modified time: 2018-01-22T15:06:45+01:00
 * @License: MIT
 */

#pragma once

#include <QMainWindow>

namespace Ui
{
    class CalculatorWindow;
}

class CalculatorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalculatorWindow( QWidget* parent = 0 );
    ~CalculatorWindow();

private:
    Ui::CalculatorWindow* ui;
};
