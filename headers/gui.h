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



#define DEFAULT_WIDTH       1920
#define DEFAULT_HEIGHT      1080 



class Gui : public QMainWindow {
    public:
        explicit Gui(QWidget *parent = nullptr);
        ~Gui();

        //getterformylightSignal array
        LightSignal* getSignal(int index);
        void INIT_SIGNALS();
    
    protected :
        void resizeEvent(QResizeEvent *event) override;
        
    private:
        Ui::GUI *ui;

        static const int signalNumber = 28;
        LightSignal* signalsArray[signalNumber];
        
        //QPushButton* m_colorButton;
    
    private slots :
        void slotMethod();
        void onColorButtonClicked();

};

#endif //GUI_H