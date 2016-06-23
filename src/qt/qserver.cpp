#include "qserver.h"
#include "clientinfo.h"

#include <QDebug>

Qserver::Qserver(QObject *parent) : QObject(parent)
{

}

void Qserver::on_N_CONNECT(server::clientinfo *ci, QString password, QString authdesc, QString authname)
{
    qDebug() << "Connected " + QString(ci->name);
}
