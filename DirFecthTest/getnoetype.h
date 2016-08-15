#ifndef GETNOETYPE_H
#define GETNOETYPE_H

#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include <QHash>

class GetNoeType
{
public:
    GetNoeType();
    QHash<QString,int>* getGuijiFileList();
};

#endif // GETNOETYPE_H
