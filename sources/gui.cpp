#include "gui.h"
#include <iostream>

Gui::Gui(QWidget *parent) : QMainWindow(parent), ui(new Ui::GUI) {
    //importe l'interface depuis le fichier .gui
    ui->setupUi(this);
    this->setWindowTitle("Tableau de commande optique");
    resize(DEFAULT_WIDTH,DEFAULT_HEIGHT);
    TEST_SETUP();
    



    // button connnection for test purposes
    connect(ui->myButton, &QPushButton::clicked, 
            this, &Gui::onColorButtonClicked);
    
}

void Gui::TEST_SETUP(){
    signalsArray[0] = new LightSignal(1, SAVL, QPoint(0, 0), this);
    signalsArray[1] = new LightSignal(2, SAVLR, QPoint(400, 400), this);
    signalsArray[2] = new LightSignal(3, CSAVLRR, QPoint(500, 500), this);
    signalsArray[3] = new LightSignal(4, CSAVLRRR, QPoint(600, 600), this);

    //signalsArray[1]->info();
    //signalsArray[1]->flipSignal();
    

    //qDebug() << "Initialization of signals made";
}

void Gui::SETUP_SIGNALS(){
    //14 exisisting signals :
    signalsArray[0] = new LightSignal(7, SAVL, QPoint(140, 850), this);
    signalsArray[1] = new LightSignal(15, SAVL, QPoint(1590, 120), this);

    signalsArray[2] = new LightSignal(1, SAVLR, QPoint(20, 340), this);
    signalsArray[3] = new LightSignal(9, SAVLR, QPoint(1800, 730), this);
    signalsArray[4] = new LightSignal(2, SAVLR, QPoint(225, 575), this);
    signalsArray[5] = new LightSignal(8, SAVLR, QPoint(1637, 600), this);

    
    signalsArray[6] = new LightSignal(13, CSAVLRR, QPoint(600,910), this);
    signalsArray[7] = new LightSignal(4, CSAVLRR, QPoint(1100, 695), this);
    signalsArray[8] = new LightSignal(12, CSAVLRR, QPoint(700, 280), this);
    signalsArray[9] = new LightSignal(5, CSAVLRRR, QPoint(960, 70), this);


    
    signalsArray[10] = new LightSignal(11, CSAVLRRR, QPoint(1445, 910), this);
    signalsArray[11] = new LightSignal(4, CSAVLRRR, QPoint(510, 685), this);
    signalsArray[12] = new LightSignal(10, CSAVLRRR, QPoint(1370, 280), this);
    signalsArray[13] = new LightSignal(3, CSAVLRRR, QPoint(420,60), this);

    for(int i = 0; i<14;i++){
        signalsArray[i]->setAspect(VL);
    }
}

void Gui::onColorButtonClicked() {
    /* for(int i = 0; i<4; i++){
        ->setAspect(S);
        update();
    } */
}

Gui::~Gui(){
    delete ui;
}

LightSignal *Gui::getSignalById(int id, int maxId)
{
   
    for(int i = 0; i < maxId;i ++){
        if(signalsArray[i]->getId() == id){
            qDebug() << "Signal found !";
            return signalsArray[i];
        }
    }
    
    qDebug() << "no signal found with this id";
    return nullptr;
    
}



/* void Gui::resizeEvent(QResizeEvent* event) {
    /* QMainWindow::resizeEvent(event);
    //qDebug() << "resize event called";


    for (int i = 0; i < 1; ++i) {
        if (signalsArray[i]) {
            signalsArray[i]->updatePosition(event->size());
        }
    }
    update(); 
} */