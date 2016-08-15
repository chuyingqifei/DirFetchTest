#include "getnoetype.h"

GetNoeType::GetNoeType()
{

}

QHash<QString,int>* GetNoeType::getGuijiFileList()
{
    QHash<QString,int> *hash = new QHash<QString,int>();
    QDir dir;

    QStringList filters;
    filters << "*.txt";
    dir.setNameFilters(filters);

    QList<QFileInfo> *fileInfo=new QList<QFileInfo>(dir.entryInfoList(filters));

    QString name;
    QStringList list;
    for(int i = 0;i<fileInfo->size();i++)
    {
        name.clear();
        list.clear();
        name = fileInfo->at(i).baseName();
        list = name.split("_");
        if(list.size() >= 2)
        {
            hash->insert(list.at(0),QString(list.at(1)).toInt());
        }
    }

    QHashIterator<QString, int> i(*hash);
    while (i.hasNext()) {
        i.next();
        qDebug() << i.key() << ": " << i.value() << endl;
    }

}
