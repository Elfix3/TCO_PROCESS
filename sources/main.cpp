#include <QApplication>
#include <QMainWindow>

//myHeadersinclude
#include "control.h"
#include "gui.h" 

#include "lightsignal.h"
#include "lightgrid.h"
#include "serialhandler.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Gui myGui;
    
    
    myGui.show();
    return app.exec();
}
