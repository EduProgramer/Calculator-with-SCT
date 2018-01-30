/**
 * @Author: jakub
 * @Project: Calculator with SCT
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
