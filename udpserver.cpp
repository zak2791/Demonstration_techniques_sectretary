#include "udpserver.h"

#include <QNetworkDatagram>
#include <QQuickItem>

UdpServer::UdpServer(QQuickWidget* qWdg, QObject *parent)
    : QObject{parent}
{
    udpSocket = new QUdpSocket(this);

    udpSocket->bind(QHostAddress::Any, 1000);

    connect(udpSocket, &QUdpSocket::readyRead,
            this, &UdpServer::readPendingDatagrams);

    QQuickItem* pqiRoot = qWdg->rootObject();
    if(pqiRoot) {
        pqiRoot->setProperty ( "color", "yellow");
        pObjText = pqiRoot->findChild<QObject*>("broadcast");
            // if (pObjText) {
            //     pObjText->setProperty ( "text", "С++") ;

                //QVariant varRet;
                // QMetaObject::invokeMethod(pObjText,
                //                           "setFontSize",
                //                            Q_RETURN_ARG(QVariant, varRet),
                //                           Q_ARG(QVariant, 52));
            //}
    }

}

void UdpServer::readPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = udpSocket->receiveDatagram();
        //processTheDatagram(datagram);
        count++;
        if (pObjText) {
            pObjText->setProperty ("text", count) ;
        }
        //qDebug()<<"datagram = "<<datagram.data();
    }
}
