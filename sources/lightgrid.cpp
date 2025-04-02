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
            grid = {QPoint(0,4),QPoint(1,4),QPoint(1,3),QPoint(1,2),QPoint(1,1),QPoint(2,1),QPoint(2,0)};
            row = 5; col = 3;
            break;
        case 9:
            grid = {QPoint(0,5),QPoint(1,5),QPoint(1,4),QPoint(1,3),QPoint(1,2),QPoint(1,1),QPoint(2,2),QPoint(2,1),QPoint(2,0)};
            row = 6 ; col = 3;
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


QVector<QRect> LightGrid::getRectPositionFromGrid(int spacing,int bulbSize){
    QVector<QRect> positions;
    positions.resize(grid.size());

    for(int i = 0; i < grid.size();i++){

        int x = grid[i].x();
        int y = grid[i].y();

        positions[i] = QRect(
            (x+1)*spacing + x*bulbSize,
            (y+1)*spacing + y*bulbSize,
            bulbSize,
            bulbSize
        );
        
    }

    return positions;
}

QSize LightGrid::getQSizeFromGrid(int spacing, int bulbSize){
    return QSize(
        col*(spacing+bulbSize) + spacing,
        row*(spacing+bulbSize)+ spacing
    );
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
/*
QPoint LightSignal::gridToWinSize(int sizeX, int sizeY){
    return QPoint(
        sizeX*(spacing+bulbSize)+ spacing,
        sizeY*(spacing+bulbSize) + spacing
    );
} */