#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QObject>
#include <QUdpSocket>
#include <QQuickWidget>

class UdpServer : public QObject
{
    Q_OBJECT
public:
    explicit UdpServer(QQuickWidget*, QObject *parent = nullptr);

private:
    void readPendingDatagrams(void);
    QUdpSocket* udpSocket;
    int count = 0;
    QObject* pObjText;

signals:
};

#endif // UDPSERVER_H
