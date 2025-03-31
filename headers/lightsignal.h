#ifndef LIGHTSIGNAL_H
#define LIGHTSIGNAL_H


#include <QWidget>
#include <QColor>
#include <Qvector>
#include <Qpainter>
#include <QDebug>
#include <QResizeEvent>

#define GRAY            0x808080
#define YELLOW          0xFFFF00
#define RED             0xFF0000
#define GREEN           0x00FF00
#define WHITE           0xFFFFFF

#define DEFAULT_WIDTH
#define DEFAULT_HEIGHT

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

        //Displays CMD info on a given Signal
        void info();
        //Sets a specific bulb to a specific color for a givan signal
        void setBulbColor(int bulbIndex, const QColor& color);
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
        QVector<QRect> lightPositions; //positions of the bulbs on the window
        QVector<QColor> lightColors; //color of the bulbs on the window



        const QPoint position; //very important this parameter is the position on a 1920*1080 window
        QPointF relativePosition; //this parameter is evaluated to each resize ()
        
        
        //bool isRelativePositionCalculated = false;

        int bulbSize = 8; //geometry parameters
        int spacing = 2;

        //signal position on the window
        QPoint gridToPixel(int posX, int posY);
        QPoint gridToWinSize(int sizeX, int sizeY);


        static const QSize REFERENCE_SIZE;

        //void updateLightPositions();



       
    

};

#endif //LIGHTSIGNAL_H