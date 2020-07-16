#include "receiver.h"

Receiver::Receiver(QObject *parent) : QObject(parent)
{

}

void Receiver::get_someting(QString s){
    qDebug()<<"Received"<<s<<endl;
}
