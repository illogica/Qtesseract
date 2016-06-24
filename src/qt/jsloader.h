#ifndef JSLOADER_H
#define JSLOADER_H

#include <QObject>
#include <QDir>
#include <QFileSystemWatcher>

extern void logoutf(const char *fmt, ...);

/**
 * @brief The JSLoader class
 * A class to automatic load .js files into QString objects
 */
class JSLoader : public QObject
{
    Q_OBJECT
public:
    explicit JSLoader(QObject *parent = 0);
    void init();
    static const QString HOMEDIR;


signals:
    void jsSourcesChanged(QStringList &sources);

public slots:
    void loadJSFiles();
    void updateJSFileWatchers();

private:
    QList<QFile*> getJsFiles();
    QList<QFileSystemWatcher*> jsFilesWatchers;

    QFileSystemWatcher *dirWatcher;
    QStringList sources;

};

#endif // JSLOADER_H
