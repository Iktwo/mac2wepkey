#ifndef NETWORKDETAILS_H
#define NETWORKDETAILS_H

#include <QObject>

class NetworkDetails : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString essid READ essid WRITE setEssid NOTIFY essidChanged)
    Q_PROPERTY(QString bssid READ bssid WRITE setBssid NOTIFY bssidChanged)
    Q_PROPERTY(int channel READ channel WRITE setChannel NOTIFY channelChanged)
    Q_PROPERTY(QString org READ org WRITE setOrg NOTIFY orgChanged)

public:
    NetworkDetails(QObject *parent=0);
    NetworkDetails(const QString &essid, const QString &bssid, const int channel,const QString &org, QObject *parent=0);

    QString essid() const;
    void setEssid(const QString &essid);

    QString bssid() const;
    void setBssid(const QString &bssid);

    int channel() const;
    void setChannel(const int channel);

    QString org() const;
    void setOrg(const QString &org);

signals:
    void essidChanged();
    void bssidChanged();
    void channelChanged();
    void orgChanged();

private:
    QString m_essid;
    QString m_bssid;
    int m_channel;
    QString m_org;
};

#endif // NETWORKDETAILS_H
