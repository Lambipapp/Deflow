#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "openingdialog.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "gsserializer.h"
#include "translator.h"
#include <QDirIterator>

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

    void TranslateAndWriteToCurrentFile();
    void SetProjectPath(const QString path);
    bool FindAndReadInputFile(QString &buffer);


    bool ReadFile(const QString &path, QString &buffer) const;




private:
    bool overwrite = false;
    GSSerializer *gss;
    QString projectPath = "";

    bool shouldOverwriteCurrentFile();
    bool ShouldOpenFile(QString filePath, QString fileName);
    void OverwriteCurrentFile();
    void OnFileOpen();
    void OnFileClose();
    void WriteToCurrentFile(const QString &);


};

#endif // FILEMANAGER_H
