#include <QObject>
#include <QtNetwork>
#include <QDebug>
#include "sender.h"
Sender::Sender(QObject *parent): QObject(parent)
{

}

void Sender::senddata(QByteArray mark)
{
    udpSocket=new QUdpSocket(this);

    udpSocket->writeDatagram(mark,QHostAddress::Broadcast,45454);
}
