#include "lightgrid.h"






LightGrid::LightGrid(int sigType){
    switch(sigType){
        case 3:
            //case for SAVL
            grid = {QPoint(0,2),QPoint(0,1),QPoint(0,0)};
            row = 3; col = 1;
            break;
        

        case 5:
            //case for SAVLR
            grid = {QPoint(0,3),QPoint(0,2),QPoint(0,1),QPoint(0,0),QPoint(1,0)};
            row = 4; col = 2;
            break;

        case 7:
            //case for CSAVLRR
            grid = {QPoint(0,6),QPoint(1,6),QPoint(1,5),QPoint(1,4),QPoint(1,2),QPoint(2,2),QPoint(2,0)};
            row = 7; col = 3;
            break;
        case 9:
            grid = {QPoint(0,6),QPoint(1,6),QPoint(1,5),QPoint(1,4),QPoint(1,2),QPoint(1,1),QPoint(2,2),QPoint(2,1),QPoint(2,0)};
            row = 7 ; col = 3;
            break;
        default :
            qDebug() << "Sorry this grid can't be constructed";
            break;
    }
    //QVector<QPoint>  lightGridCSAVLRR = 
        //QVector<QPoint>  lightGridCSAVLRRR = 
}

LightGrid::~LightGrid(){
}


QVector<QRect> LightGrid::getRectPositionFromGrid(){
    QVector<QRect> positions;
    positions.resize(grid.size());

    for(int i = 0; grid.size();i++){

    }
}

/* QVector<QRect> LightSignal::getRectPositionsFromGrid(QVector<QPoint> myGrid){
    //this funciton purpose, is to calculate the rect position considering the grid which is given
    QVector<QRect> positions;
    positions.resize(myGrid.size());


    //itteration on grid element
    for(int i = 0; i<myGrid.size();i++){

        //computations of the QRect :


      positions[i]  = gridToPixel(myGrid[i]);
    }

    return positions;
}

QRect LightSignal::gridToPixel(QPoint myQpoint){
    int posX = myQpoint.x();
    int posY = myQpoint.y();
    return QRect(
        (posX+1)*spacing + posX*(bulbSize),
        (posY+1)*spacing + posY*(bulbSize),
        bulbSize,
        bulbSize

    );
}
 */