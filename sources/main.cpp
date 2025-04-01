#include <QApplication>
#include <QMainWindow>

//myHeadersinclude
#include "control.h"
#include "gui.h" 
#include "lightsignal.h"
#include "lightgrid.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Gui myGui;
    //myGui.getSignal(0)->move(QPoint(800,800));
    LightGrid *grid = new LightGrid(9);
    
    myGui.show(); 
    return app.exec();
}
