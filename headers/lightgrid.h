#ifndef LIGHTGRID_H
#define LIGHTGRID_H

#include <QVector>
#include <QPoint>
#include <QDebug>
#include <Qsize>

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


        QVector<QRect> getRectPositionFromGrid();
        //void rotateGrid(Rotation rotate); 

 };


#endif ///LIGHTGRID_H 