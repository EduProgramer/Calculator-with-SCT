/**
 * @Author: Jakub
 * @Date:   2018-01-22T15:06:31+01:00
 * @Project: Calculator with SCT
 * @Last modified by:   Jakub
 * @Last modified time: 2018-01-22T15:09:06+01:00
 * @License: MIT
 */

#include "CalculatorWindow.hpp"
#include <QApplication>

#ifdef SCT_SERVER
#include "sct/SctServer.hpp"
#endif

int main( int argc, char* argv[] )
{
    QApplication a( argc, argv );
    CalculatorWindow w;
    w.show();

#ifdef SCT_SERVER
    SctServer sctServer( w );
#endif

    return a.exec();
}
