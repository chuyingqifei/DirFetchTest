#ifndef GETBROADCASTADDRESS_H
#define GETBROADCASTADDRESS_H
#include <QStringList>
#include <QNetworkInterface>

class GetBroadcastAddress
{
public:
    GetBroadcastAddress();
    int getBroadcastAddressList(QStringList& list);
    void getNetworkInfo();


    QStringList devIdList;
    QStringList ipList;
    QStringList netmaskList;
    QStringList subnetList;
    QStringList subnetBroadcastList;
};

#endif // GETBROADCASTADDRESS_H
