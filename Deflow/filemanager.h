#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "openingdialog.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

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


private:
    bool overwrite = false;

    bool shouldOverwriteCurrentFile();
    bool ShouldOpenFile(QString filePath, QString fileName);
    void OverwriteCurrentFile();
    void OnOpenFile();
    void OnFileClose();

};

#endif // FILEMANAGER_H
