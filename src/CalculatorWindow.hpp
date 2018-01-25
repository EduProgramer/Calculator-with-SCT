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

private slots:
    void on_inputNum0_clicked();
    void on_inputNum1_clicked();
    void on_inputNum2_clicked();
    void on_inputNum3_clicked();
    void on_inputNum4_clicked();
    void on_inputNum5_clicked();
    void on_inputNum6_clicked();
    void on_inputNum7_clicked();
    void on_inputNum8_clicked();
    void on_inputNum9_clicked();

    void on_inputOperDivis_clicked();
    void on_inputOperMinus_clicked();
    void on_inputOperMulti_clicked();
    void on_inputOperPlus_clicked();

private:
    Ui::CalculatorWindow* ui;
};
