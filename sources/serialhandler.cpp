#include "serialhandler.h"

SerialHandler::SerialHandler(QObject *parent) : QObject(parent), serialPort(new QSerialPort(this)){
    qDebug() << "Serial Handler Created :)";
}

SerialHandler::~SerialHandler(){
    if (serialPort->isOpen()) {
        serialPort->close();
        qDebug() << "Serial Handler deleted :(";
    }
}

void SerialHandler::disconnectPort(){
    if(serialPort->isOpen()){
        serialPort->close();
        qDebug() << "Port successfully closed";
    }
}

bool SerialHandler::isPortOpen(){
    return serialPort->isOpen();
}
void SerialHandler::setupSerialPort(const QString &portName, qint32 baudRate){
    serialPort->setPortName(portName);  // Choisir le port série
    serialPort->setBaudRate(baudRate);  // Vitesse de transmission
    serialPort->setDataBits(QSerialPort::Data8);  // 8 bits de données
    serialPort->setParity(QSerialPort::NoParity);  // Pas de parité
    serialPort->setStopBits(QSerialPort::OneStop);  // 1 bit de stop
    serialPort->setFlowControl(QSerialPort::NoFlowControl);  // Pas de contrôle de flux

    connect(serialPort, &QSerialPort::readyRead, this, &SerialHandler::onDataReceived);

    if (!serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Failed to open port";
    } else {
        qDebug() << "Port opened successfully";
    }

}

/* void SerialHandler::onDataReceived(){
    QByteArray data = serialPort->readAll();
    // Convertir QByteArray en QString
    QString strData = QString::fromUtf8(data);
    
    emit dataReceived(strData);
    // Pour le débogage
    qDebug() << "Data received:" << strData;
} */


void SerialHandler::onDataReceived() {
    QByteArray data = serialPort->readAll();

    // Tampon pour stocker les données reçues
    static QByteArray buffer;

    // Ajouter les données lues au tampon
    buffer.append(data);

    // Vérifier si une ligne complète est reçue (une ligne terminée par '\n')
    int pos = buffer.indexOf('\n');
    while (pos != -1) {
        // Extraire la ligne complète (avant le '\n')
        QByteArray line = buffer.left(pos);
        
        // Convertir la ligne en QString
        QString strData = QString::fromUtf8(line);

        // Émettre les données reçues
        emit dataReceived(strData);

        // Pour le débogage
        qDebug() << "Data received:" << strData;

        // Supprimer la ligne traitée du tampon (tout avant et y compris '\n')
        buffer.remove(0, pos + 1);

        // Chercher une autre ligne complète
        pos = buffer.indexOf('\n');
    }
}

