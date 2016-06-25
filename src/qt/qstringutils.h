#ifndef QSTRINGUTILS_H
#define QSTRINGUTILS_H

#include <QString>
#include "typedefs.h"

char * qstrtochar(QString s){
    QByteArray local8Bit = s.toLocal8Bit();
    char *cdata = local8Bit.data();
    return cdata;
}

#endif // QSTRINGUTILS_H
