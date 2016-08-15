#include "getbroadcastaddress.h"

GetBroadcastAddress::GetBroadcastAddress()
{

}

int GetBroadcastAddress::getBroadcastAddressList(QStringList& mylist)
{
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
         //获取所有网络接口的列表
    foreach(QNetworkInterface interface,list)
    {
        //遍历每一个网络接口
        //qDebug() << "Device: "<<interface.name();                          //设备名

        //qDebug() << "HardwareAddress: "<<interface.hardwareAddress();      //硬件地址
        QList<QNetworkAddressEntry> entryList = interface.addressEntries();
        //获取IP地址条目列表，每个条目中包含一个IP地址，一个子网掩码和一个广播地址
        foreach(QNetworkAddressEntry entry,entryList)
        {
            //遍历每一个IP地址条目
            qDebug()<<"IP Address: "<<entry.ip().toString()<<"size = "<<entry.ip().toString().length();            //IP地址
            qDebug()<<"Netmask: "<<entry.netmask().toString()<<"size = "<<entry.netmask().toString().length();          //子网掩码
            qDebug()<<"Broadcast: "<<entry.broadcast().toString()<<"size = "<<entry.broadcast().toString().length();      //广播地址
        }
    }
}

void GetBroadcastAddress::getNetworkInfo()
{
    devIdList.clear();
    ipList.clear();
    netmaskList.clear();

    //qDebug()<<"setNetWidget()"<<ui->net_widget->rowCount()<<":"<<ui->net_widget->columnCount();
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
         //获取所有网络接口的列表
    foreach(QNetworkInterface interface,list)
    {
        //遍历每一个网络接口
        //qDebug() << "Device: "<<interface.name();                          //设备名
        if(!interface.name().contains("eth"))
        {
            continue;
        }
        devIdList << interface.name();
        //qDebug() << "HardwareAddress: "<<interface.hardwareAddress();      //硬件地址
        QList<QNetworkAddressEntry> entryList = interface.addressEntries();
        //获取IP地址条目列表，每个条目中包含一个IP地址，一个子网掩码和一个广播地址
        foreach(QNetworkAddressEntry entry,entryList)
        {
            //遍历每一个IP地址条目
            if(entry.netmask().toString().length() > 15) //过滤IPv6地址
            {
                continue;
            }
            ipList << entry.ip().toString();
            netmaskList << entry.netmask().toString();

            qDebug()<<"IP Address: "<<entry.ip().toString()<<"size = "<<entry.ip().toString().length();            //IP地址
            qDebug()<<"Netmask: "<<entry.netmask().toString()<<"size = "<<entry.netmask().toString().length();          //子网掩码
            qDebug()<<"Broadcast: "<<entry.broadcast().toString()<<"size = "<<entry.broadcast().toString().length();      //广播地址
        }
   }
}

