#include "lightsignal.h"


LightSignal::LightSignal(int id, const SignalType type, const QPoint position, QWidget *parent) :
    QWidget(parent),
    signalType(type),
    currentAspect(IDLE),
    id(id),
    position(position),
    lightGrid(type)

{
    



    //sets the correct vector sizes for the color and the position of the bulb
    lightColors.resize(signalType);
    lightPositions.resize(signalType);

    //fill all colors with gray for initial IDLE state
    for (QColor& color : lightColors) {
        color = QColor(OFF);
    }

    //lightGrid = LightGrid(type);
    setFixedSize(lightGrid.getQSizeFromGrid(spacing, bulbSize));
    lightPositions = lightGrid.getRectPositionFromGrid(spacing, bulbSize);
    



    move(position);
    qDebug() <<"Object" << id << "constructed";
}

LightSignal::~LightSignal(){
    qDebug() <<"Object" << id << "destroyed";

}

int LightSignal::getId(){
    return id;
}

void LightSignal::flipSignal(){
    
}

void LightSignal::info()
{   
    const char* aspectNames[] = {"IDLE", "VL", "A", "S", "C", "R", "RR"};
    const char* signalTypesNames[] = {"SAVL","SAVLR","CSAVLR","CSAVLRRR"};

    //qDebug() << (signalType-3)/2;
    qDebug() << "===============================";
    qDebug() << "=== LightSignal Information ===";
    qDebug() << "===============================";

    qDebug("\nObject infos :");
    qDebug() << "       Signal Id:" << id;
    qDebug() << "       Signal Type:" << signalTypesNames[(int)(signalType-3)/2];
    qDebug() << "       Aspect :" << aspectNames[currentAspect];
    //qDebug() << "       Position: (" << position.x() << "," << position.y() << ")";
    
    
    
    
    qDebug() << "\nBulb Configuration:";
    for (int i = 0; i < signalType; ++i) {
        qDebug() << "       Bulb" << i+1 << ":"
                 << "   Pos(" << lightPositions[i].x() << "," << lightPositions[i].y() << ")"
                 << "   Color:" << lightColors[i].name();
    }
    
    qDebug() << "\nPhysical Properties:";
    qDebug() << "       Bulb Size:" << bulbSize << "px";
    qDebug() << "       Spacing:" << spacing << "px";
        qDebug() << "       Total Size:" << width() << "x" << height() << "px";
        qDebug() << "=============================";
}

void LightSignal::paintEvent(QPaintEvent *event)
{

    //consider painting depending on the sigType (for oeilleton notamment);
    Q_UNUSED(event); // Mark unused parameter
    
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // Smooth circles
    
    //painter.fillRect(rect(), QColor(GRAY));

    // Draw each bulb
    for (int i = 0; i < lightPositions.size(); ++i) {
        // Set the bulb color
        painter.setBrush(lightColors[i]);
        
        // Draw a simple circle for the bulb
        painter.drawEllipse(lightPositions[i]);
    }
}

void LightSignal::updatePosition(const QSize& newWindowSize) {
    // 1. Validation des entrées
    if (newWindowSize.isEmpty()) {
        qWarning() << "Taille fenêtre invalide";
        return;
    }
    
    if (position.isNull()) {
        qWarning() << "Position initiale non définie";
        return;  // On quitte car le calcul serait invalide
    }

    // 2. Déclaration des tailles de référence (à mettre en constante de classe)
    const QSize referenceSize(1920, 1080);
    
    // 3. Calcul des nouvelles positions avec précision
    double ratioX = static_cast<double>(position.x()) / referenceSize.width();
    double ratioY = static_cast<double>(position.y()) / referenceSize.height();
    
    int newX = static_cast<int>(ratioX * newWindowSize.width());
    int newY = static_cast<int>(ratioY * newWindowSize.height());

    // 4. Validation des nouvelles positions
    if (newX < 0 || newY < 0 || newX >= newWindowSize.width() || newY >= newWindowSize.height()) {
        qWarning() << "Nouvelle position hors limites";
        return;
    }

    // 5. Application du déplacement
    move(newX, newY);
    update();

    // 6. Debug (optionnel)
    qDebug() << "Redimensionnement - Ancienne:" << position 
             << "Nouvelle:" << QPoint(newX, newY)
             << "Taille fenêtre:" << newWindowSize;
}




void LightSignal::setBulbColor(int bulbIndex, const QColor& color) {
    if (bulbIndex >= 0 && bulbIndex < lightColors.size()) {
        lightColors[bulbIndex] = color;
        update(); // Trigger repaint
    } else {
        qWarning() << "Invalid bulb index:" << bulbIndex;
    }
}

void LightSignal::resetAspet(){
    for(QColor& color : lightColors){
        color = QColor(OFF);
    }

}

void LightSignal::setAspect(Aspect newAspect){

    //sets the signal to an IDLE aspect
    resetAspet();

    switch(newAspect){
        case VL:
            if(signalType == SAVL || signalType == SAVLR){
                lightColors[2] = QColor(GREEN);
            } else {
                lightColors[3] = QColor(GREEN);
            }
            break;
        case A:
            if(signalType == SAVL || signalType == SAVLR){
                lightColors[0] = QColor(YELLOW);
            } else {
                lightColors[1] = QColor(YELLOW);
            }
            break;
        case S:
            if(signalType == SAVL || signalType == SAVLR){
                lightColors[1] = QColor(RED);
            } else {
                lightColors[2] = QColor(RED);
                lightColors[0] = QColor(WHITE);
            }
            
            break;
        case C:
            if(!(signalType == SAVL || signalType == SAVLR)){
                lightColors[2] = QColor(RED); lightColors[4] =  QColor(RED);
            } else {
                qDebug() << "Cannot display carré on SAVL or SAVLR";
            }
            break;
        case R:
            if(signalType == SAVLR){
                lightColors[3] = QColor(YELLOW); lightColors[4] = QColor(YELLOW);
            } else if(signalType == CSAVLRRR){
                lightColors[5] = QColor(YELLOW); lightColors[7] = QColor(YELLOW);
            } else {
                qDebug() << "Cannot display ralentissement on SAVL or CSAVLRR";
            }
            break;
        case RR:
            if(signalType == CSAVLRRR){
                lightColors[6] = QColor(YELLOW); lightColors[8] = QColor(YELLOW);
            } else if(signalType == CSAVLRR){
                lightColors[5] = QColor(YELLOW); lightColors[6] = QColor(YELLOW);
            } else {
                qDebug() <<"Cannot display rappel ralentissement on SAVL or SAVLR";
            }
            break;
        default: //SET to IDDLE ?? nothing to do then
            break;
    }

}


/*
QPoint LightSignal::gridToWinSize(int sizeX, int sizeY){
    return QPoint(
        sizeX*(spacing+bulbSize)+ spacing,
        sizeY*(spacing+bulbSize) + spacing
    );
} */
