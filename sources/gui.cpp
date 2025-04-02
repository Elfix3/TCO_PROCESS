#include "gui.h"
#include <iostream>

Gui::Gui(QWidget *parent) : QMainWindow(parent), ui(new Ui::GUI) {
    //importe l'interface depuis le fichier .gui
    ui->setupUi(this);
    this->setWindowTitle("Tableau de commande optique");



    //FenÛtre en plein Úcran | Taille : QSize(1920, 1009)

    qDebug() << this->size();
    resize(DEFAULT_WIDTH,DEFAULT_HEIGHT);
    qDebug() << this->size();
    TEST_SETUP();
    

    SerialHandler *mySerialHandler = new SerialHandler(this);
    mySerialHandler->setupSerialPort("COM5",QSerialPort::Baud9600);

    connect(mySerialHandler, &SerialHandler::dataReceived, 
        this, &Gui::onSerialDataReceived);

    // button connnection for test purposes
    connect(ui->myButton, &QPushButton::clicked, 
            this, &Gui::onColorButtonClicked);
    
}

Gui::~Gui(){
    delete ui;
}


void Gui::TEST_SETUP(){
    signalsArray[0] = new LightSignal(1, SAVL, QPoint(0, 0), this);
    signalsArray[1] = new LightSignal(2, SAVLR, QPoint(400, 400), this);
    signalsArray[2] = new LightSignal(3, CSAVLRR, QPoint(500, 500), this);
    signalsArray[3] = new LightSignal(4, CSAVLRRR, QPoint(600, 600), this);

    //signalsArray[0]->setAspect(S);
    //signalsArray[1]->setAspect(A);
    signalsArray[2]->setAspect(VL);
    //signalsArray[3]->setAspect(R);
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

void Gui::onSerialDataReceived(const QString &data){
    if (data.trimmed() == "low") {
        signalsArray[2]->setAspect(IDLE);
    } else if (data.trimmed() == "high"){
        signalsArray[2]->setAspect(C);  
    }
    update();
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



void Gui::resizeEvent(QResizeEvent* event) {
    QMainWindow::resizeEvent(event);
    
    int width = this->size().width();
    int height = this->size().height();

    signalsArray[0]->move(width*0.7,height*0.5);
    signalsArray[1]->move(width*0.8,height*0.5);
    signalsArray[2]->move(width*0.1,height*0.44);
    signalsArray[3]->move(width*0.3,height*0.5);
}


void Gui::changeEvent(QEvent *event) {
    if (event->type() == QEvent::WindowStateChange) {
        if (this->isMaximized()) {
            qDebug() << "Fenêtre en plein écran | Taille :" << this->size();

        } else if (this->isFullScreen()) {
            qDebug() << "Mode plein écran (sans bordure) | Taille :" << this->size();
        } else {
            qDebug() << "Fenêtre restaurée | Taille :" << this->size();
        }
    }
    QMainWindow::changeEvent(event); // Important : appeler l'implémentation parente
}