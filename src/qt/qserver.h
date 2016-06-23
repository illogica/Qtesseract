#ifndef QSERVER_H
#define QSERVER_H

#include <QObject>
#include <QString>

namespace server{
    class clientinfo;
}

/**
 * @brief The Qserver class
 *
 * note to self: QString uses COW, so it's efficient even without passing it by reference.
 */

class Qserver : public QObject
{
    Q_OBJECT
public:
    explicit Qserver(QObject *parent = 0);

signals:

public slots:

    void on_N_CONNECT(server::clientinfo *ci, QString password, QString authdesc, QString authname);
};

#endif // QSERVER_H
