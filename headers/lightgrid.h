#ifndef LIGHTGRID_H
#define LIGHTGRID_H

/*
This class allows the managment of some "grid" with coordinates.
These coordinates can then be converted into pixel values, considering a given spacing and bulbSize (bcs of some circular objects)
Thanks to these pixel conversions, this can be displayed as a widget
*/


#include <QVector>
#include <QPoint>
#include <QDebug>
#include <Qsize>
#include <QRect>
enum Rotation{
    LEFT_90,
    RIGHT_90,
    UPSDWN_180
};



class LightGrid{
    private:
    QVector<QPoint> grid;
    int row,col;

    public:
        LightGrid(int sigType);
        ~LightGrid();


        QVector<QRect> getRectPositionFromGrid(int spacing,int bulbSize);
        QSize getQSizeFromGrid(int spacing, int bulbSize);
        //void rotateGrid(Rotation rotate); 

 };


#endif ///LIGHTGRID_H 