#include "gui.h"
#include <iostream>

Gui::Gui(QWidget *parent) : QMainWindow(parent), ui(new Ui::GUI) {
    //importe l'interface depuis le fichier .gui
    ui->setupUi(this);
    this->setWindowTitle("Tableau de commande optique");
    resize(DEFAULT_WIDTH,DEFAULT_HEIGHT);
    INIT_SIGNALS();
    



    // button connnection for test purposes
    connect(ui->myButton, &QPushButton::clicked, 
            this, &Gui::onColorButtonClicked);
    
}

void Gui::INIT_SIGNALS(){
    signalsArray[0] = new LightSignal(1, SAVL, QPoint(0, 0), this);
    signalsArray[1] = new LightSignal(2, SAVLR, QPoint(150, 150), this);
    signalsArray[2] = new LightSignal(3, CSAVLRR, QPoint(300, 300), this);
    signalsArray[3] = new LightSignal(4, CSAVLRRR, QPoint(450, 450), this);


    qDebug() << "Initialization of signals made";
}


void Gui::onColorButtonClicked() {
    for(int i = 0; i<4; i++){
        getSignal(i)->setAspect(S);
        update();
    }
}

Gui::~Gui(){
    delete ui;
}

LightSignal *Gui::getSignal(int index)
{
    if(index>=0 && index<signalNumber){

        return signalsArray[index];
    } else {
        return nullptr;
    }
}



void Gui::resizeEvent(QResizeEvent* event) {
    QMainWindow::resizeEvent(event);
    qDebug() << "resize event called";


    for (int i = 0; i < 1; ++i) {
        if (signalsArray[i]) {
            signalsArray[i]->updatePosition(event->size());
        }
    }
    update();
}