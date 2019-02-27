#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "openingdialog.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "gsserializer.h"

class FileManager
{
public:
    FileManager();
    ~FileManager();


    bool OpenFile(QString filePath, QString fileName);
    void CloseCurrentFile();



    QFile currentFile;
    OpeningDialog* od;

    static FileManager *fm;
    void SetGSS(GSSerializer *p);

private:
    bool overwrite = false;
    GSSerializer *gss;
    bool shouldOverwriteCurrentFile();
    bool ShouldOpenFile(QString filePath, QString fileName);
    void OverwriteCurrentFile();
    void OnFileOpen();
    void OnFileClose();

};

#endif // FILEMANAGER_H
