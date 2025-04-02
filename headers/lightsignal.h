#ifndef LIGHTSIGNAL_H
#define LIGHTSIGNAL_H


#include <QWidget>
#include <QColor>
#include <Qvector>
#include <Qpainter>
#include <QDebug>
#include <QResizeEvent>


#include "lightgrid.h"


//color palette
#define GRAY            0x808080
#define OFF             0x400b06
#define YELLOW          0xFFFF00
#define RED             0xFF0000
#define GREEN           0x00FF00
#define WHITE           0xFFFFFF

//#define DEFAULT_WIDTH
//#define DEFAULT_HEIGHT

enum SignalType {
    SAVL = 3, 
    SAVLR = 5,
    CSAVLRR = 7,
    CSAVLRRR = 9
};

enum Aspect{
    IDLE, //inactif
    VL, //Voie libre
    A, //Avertissement
    S, //Sémaphore
    C, //Carré
    R, //Ralentissement
    RR // Rappel ralentissement
};


 
class LightSignal : public QWidget
{
    Q_OBJECT


    public:
        explicit LightSignal(int id, const SignalType type, const QPoint position, QWidget *parent = nullptr);
        ~LightSignal();

        int getId();

        void flipSignal();
        //Displays CMD info on a given Signal
        void info();
        //Sets a specific bulb to a specific color for a givan signal 
        void setBulbColor(int bulbIndex, const QColor& color); //not really usefull
        
        void resetAspet();
        //Sets an aspect(VL S C, etc.) on a signal
        void setAspect(Aspect newAspect);
        

        void updatePosition(const QSize& newWindowSize);

    signals:
        //void aspectChanged(Aspect newAspect);
        //void signalConfigured();
        //void errorOccurred(const QString& message);

    protected:
        void paintEvent(QPaintEvent *event) override;
        //void resizeEvent(QResizeEvent *event) override;
        //void resizeEvent(QResizeEvent *event) override;

    private:
        int id;
        Aspect currentAspect;  //what the signal displays
        const SignalType signalType; //the signal configuration, which is also the number of bulbs
        LightGrid lightGrid;
        QVector<QRect> lightPositions; //positions of the bulbs on the window
        QVector<QColor> lightColors;//color of the bulbs on the window



        const QPoint position; //very important this parameter is the position on a 1920*1080 window
        QPointF relativePosition; //this parameter is evaluated to each resize ()
        
        
        //light dispositions in a grid :

        //LightGrid lightGridSAVL = LightGrid(SAVL);
        //LightGrid lightGridSAVLR = LightGrid(SAVLR);
        //LightGrid lightGridCSAVLRR = LightGrid(CSAVLRR);
        //LightGrid lightGridCSAVLRRR = LightGrid(CSAVLRRR);

        int bulbSize = 9; //geometry parameters (default 8,3)
        int spacing = 3;

        //signal position on the window
        //QVector<QRect> getRectPositionsFromGrid(QVector<QPoint> myGrid);
        //void rotateGrid();
        //QRect gridToPixel(QPoint myQpoint);
        /*QPoint gridToWinSize(int sizeX, int sizeY); */


        static const QSize REFERENCE_SIZE;

        //void updateLightPositions();



       
    

};

#endif //LIGHTSIGNAL_H