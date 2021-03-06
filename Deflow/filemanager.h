#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "openingdialog.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "translator.h"
#include <QDirIterator>

class FileManager : public QObject
{
    Q_OBJECT

public:
    FileManager();
    ~FileManager();


    bool OpenFile(QString filePath, QString fileName);
    void CloseCurrentFile();



    QFile currentFile;
    OpeningDialog* od;

    static FileManager *fm;


    void SetProjectPath(const QString path);
    bool FindAndReadInputFile(QString &buffer);


    bool ReadFile(const QString &path, QString &buffer) const;




private:
    bool overwrite = false;
    QString projectPath = "";

    bool shouldOverwriteCurrentFile();
    bool ShouldOpenFile(QString filePath, QString fileName);
    void OverwriteCurrentFile();
    void OnFileOpen();
    void OnFileClose();
    void WriteToCurrentFile(const QString &);

public slots:
        void TranslateAndWriteToCurrentFile();


};

#endif // FILEMANAGER_H
