#include "jsloader.h"

const QString JSLoader::HOMEDIR = QString("src/js/");

JSLoader::JSLoader(QObject *parent) : QObject(parent)
{

}

void JSLoader::init()
{
    loadJSFiles();
    dirWatcher = new QFileSystemWatcher();
    if(!dirWatcher->addPath(HOMEDIR)){
        logoutf("ERROR: could not initialize file system watcher");
    }
    connect(dirWatcher, SIGNAL(directoryChanged(QString)), this, SLOT(loadJSFiles()));
    connect(dirWatcher, SIGNAL(directoryChanged(QString)), this, SLOT(updateJSFileWatchers()));

    updateJSFileWatchers();
}

void JSLoader::loadJSFiles()
{

    jsFiles = getJsFiles();

    QStringList newSources;
    for(int i=0; i<jsFiles.size(); i++){
        if (!(jsFiles.at(i)->open(QIODevice::ReadOnly | QIODevice::Text))){
            QString current = jsFiles.at(i)->fileName();
            QByteArray ba = current.toLatin1();
            const char *c_str2 = ba.data();
            logoutf("cannot open file %s", c_str2);
            return;
        }
        QString fileContent = jsFiles.at(i)->readAll();
        newSources.append(fileContent);
        jsFiles.at(i)->close();
    }

    //only if everything went fine:
    sources.clear();
    for(int i=0; i<newSources.size(); i++){
        sources.append(newSources.at(i));
    }

    emit jsSourcesChanged(sources);
}

void JSLoader::updateJSFileWatchers()
{
    for(int i=0; i<jsFilesWatchers.size(); i++){
        jsFilesWatchers.at(i)->disconnect();
        delete jsFilesWatchers.at(i);
    }
    jsFilesWatchers.clear();

    jsFiles = getJsFiles();
    for(int i=0; i<jsFiles.size(); i++){
        QFileSystemWatcher* watcher = new QFileSystemWatcher();
        watcher->addPath(jsFiles.at(i)->fileName());
        connect(watcher, SIGNAL(fileChanged(QString)), this, SLOT(loadJSFiles()));
        jsFilesWatchers.append(watcher);
    }
}

QList<QFile*> JSLoader::getJsFiles()
{
    for(QFile* f : jsFiles){
        delete f;
    }
    jsFiles.clear();

    QDir jsDir(HOMEDIR);
    if(!jsDir.exists()){
        logoutf("ERROR: Cannot find js directory");
        return jsFiles;
    }

    jsDir.setFilter(QDir::Files | QDir::NoSymLinks);
    jsDir.setSorting(QDir::Name);
    QStringList nameFilters;
    nameFilters << "*.js" << "*.qs";
    jsDir.setNameFilters(nameFilters);
    QStringList jsFileNames = jsDir.entryList();
    for(int i=0; i<jsFileNames.size(); i++){
        jsFiles.append(new QFile(HOMEDIR + jsFileNames.at(i)));
    }
    return jsFiles;
}
