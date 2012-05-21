#ifndef WMAIN_H
#define WMAIN_H

#include <QApplication>
#include <QDeclarativeItem>
#include <QDeclarativeEngine>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QRegExp>
#include <QtGui>
#include <QDBusInterface>
#include <QFile>

#include "networkdetails.h"
#include <stdint.h>

class QDBusMessage;

class WMain : public QObject
{
    Q_OBJECT
public:
    explicit WMain(QWidget *parent = 0);

signals:

public slots:
    QString getHuaweiKey(QString mac);
    QString getHuaweiSSID(QString mac);
    QString getKey(QString mac);
    void wlanScanResults(const QDBusMessage &status);
    void addNetwork(QString essid, QString bssid, int channel,QString org);
    void startScan();
    QString getOrg(QString oui);
    QString getTelseyKey(QString mac);
    uint32_t telsey_hashword(const uint32_t * k,size_t length, uint32_t initval);

private:
    QDeclarativeView *view;
    QDeclarativeContext *rootContext;
    QList<QObject*> networksList;
};

#endif // WMAIN_H
