#ifndef SENDER_H
#define SENDER_H

#include <QObject>
QT_BEGIN_NAMESPACE

class QUdpSocket;
QT_END_NAMESPACE

class Sender : public QObject
{
    Q_OBJECT

public:
    Sender(QObject *parent = 0);



    void senddata(QByteArray);

private:

    QUdpSocket *udpSocket;

};
#endif // SENDER_H

