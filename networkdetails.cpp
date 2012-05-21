#include <QDebug>
#include "networkdetails.h"

NetworkDetails::NetworkDetails(QObject *parent)
    : QObject(parent)
{
}

NetworkDetails::NetworkDetails(const QString &essid, const QString &bssid, const int channel, const QString &org, QObject *parent)
    : QObject(parent), m_essid(essid), m_bssid(bssid), m_channel(channel), m_org(org)
{
}

QString NetworkDetails::essid() const
{
    return m_essid;
}

void NetworkDetails::setEssid(const QString &essid)
{
    if (essid != m_essid) {
        m_essid = essid;
        emit essidChanged();
    }
}

QString NetworkDetails::bssid() const
{
    return m_bssid;
}

void NetworkDetails::setBssid(const QString &bssid)
{
    if (bssid != m_bssid) {
        m_bssid = bssid;
        emit bssidChanged();
    }
}

int NetworkDetails::channel() const
{
    return m_channel;
}

void NetworkDetails::setChannel(const int channel){
    if (channel != m_channel) {
        m_channel = channel;
        emit channelChanged();
    }
}


QString NetworkDetails::org() const
{
    return m_org;
}

void NetworkDetails::setOrg(const QString &org){
    if (org != m_org) {
        m_org = org;
        emit orgChanged();
    }
}
