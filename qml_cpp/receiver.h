#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QDebug>
class Receiver : public QObject
{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = nullptr);

signals:
public slots:
    void get_someting(QString s);
};

#endif // RECEIVER_H
