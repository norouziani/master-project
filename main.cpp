#include "sender.h"
#include "receiver.h"
#include <iostream>
#include <QApplication>
#include<QDebug>
using namespace std;

int main()
{
    Receiver receiver;
    while((receiver.processPendingDatagrams())!=1919)
    {        
        receiver.processPendingDatagrams();
    }
    Sender sender;
    sender.senddata(receiver.average1());

}

