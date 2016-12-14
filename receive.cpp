#include <QtNetwork>
#include <iostream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
#include "sender.h"
#include "receiver.h"

using namespace std;


Receiver::Receiver(QObject *parent): QObject(parent)
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(45454, QUdpSocket::ShareAddress);
    connect(udpSocket, SIGNAL(readyRead()),this, SLOT(processPendingDatagrams()));
}

float Receiver::processPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        auto json_doc=QJsonDocument::fromJson(datagram);
        QJsonObject json_obj=json_doc.object();
        QVariantMap json_map = json_obj.toVariantMap();
        float mrk = json_map["mark"].toFloat();
        float unt = json_map["unit"].toFloat();
        QString lesson=json_map["lesson"].toString();
        if(mrk!=1919)
        {
            subm+=(mrk*unt);
            subu+=unt;
            average=subm/subu;
            qDebug()<<lesson<<mrk<<unt;
        }

        return(mrk);
    }


}


QByteArray Receiver::average1()
{


    QString b;
    b.setNum(average);

    QJsonObject Average;
    Average["data"] = b;

    QJsonDocument doc(Average);
    QByteArray bytes1 = doc.toJson();
    qDebug()<<average;
  return(bytes1);
}
