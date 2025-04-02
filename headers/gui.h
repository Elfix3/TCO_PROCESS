#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QVector>
#include <QPainter>
#include <QLabel>
#include <QPixmap>
#include <QImage>
#include <QDebug>
#include <QPalette>
#include <QMessageBox>


#include "ui_gui.h"
#include "lightsignal.h"
#include "serialhandler.h"



#define DEFAULT_WIDTH       1920
#define DEFAULT_HEIGHT      1080 



class Gui : public QMainWindow {
    public:
        explicit Gui(QWidget *parent = nullptr);
        ~Gui();

        //getter for a signal with its id
        LightSignal* getSignalById(int id, int maxId);
        void TEST_SETUP();
        void SETUP_SIGNALS();
    
    protected :
        void changeEvent(QEvent *event);
        void resizeEvent(QResizeEvent *event) override;
        
    private:
        Ui::GUI *ui;

        static const int signalNumber = 28;
        LightSignal* signalsArray[signalNumber];
        
        //QPushButton* m_colorButton;
    
    private slots :
        void slotMethod();
        void onColorButtonClicked();
        void onSerialDataReceived(const QString &data);

};

#endif //GUI_H