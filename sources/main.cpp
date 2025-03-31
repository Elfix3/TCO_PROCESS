#include <QApplication>
#include <QMainWindow>

//myHeadersinclude
#include "control.h"
#include "gui.h" 
#include "lightsignal.h"



int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Gui myGui;
    myGui.getSignal(0)->move(QPoint(800,800));
    
    
    myGui.show(); 
    return app.exec();
}
