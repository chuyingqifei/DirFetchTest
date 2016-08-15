#include <QCoreApplication>
#include <getnoetype.h>
#include <getbroadcastaddress.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    GetNoeType gg;
//    gg.getGuijiFileList();

    GetBroadcastAddress gb;
    gb.getNetworkInfo();

    return a.exec();
}
