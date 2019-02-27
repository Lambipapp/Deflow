#ifndef GSSERIALIZER_H
#define GSSERIALIZER_H

#include <QWidget>
#include "blocks.h"
#include "canvas.h"
#include <QTextStream>
#include <QFile>
#include <QDir>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "blocks.h"

class GSSerializer
{
public:
    GSSerializer(QString projectPath);
    ~GSSerializer();
    void SaveCurrentFile(QString file);
    void LoadFromFile(QString scriptName);

private:

    QString projectPath;
    QString fileSuffix = ".dfc";
    QString folderName = "deflowAssets/";
    QString folder;
    void SerializeToFile(QFile* file);
    void ParseSaveFile(QFile* file);
};

#endif // GSSERIALIZER_H
