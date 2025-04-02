#ifndef SERIALHANDLER_H
#define SERIALHANDLER_H

#include <QDebug>
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>

class SerialHandler : public QObject{
    Q_OBJECT


    public:
        explicit SerialHandler(QObject *parent = nullptr);
        ~SerialHandler();

        void disconnectPort();
        bool isPortOpen();
        void setupSerialPort(const QString &portName, qint32 baudRate = QSerialPort::Baud9600);

    signals :
        void dataReceived(const QString &data);

    private slots :
        void onDataReceived();

    private :
        QSerialPort *serialPort;
};
#endif //SERIALHANDLER_H