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


class GSSerializer
{
public:
    GSSerializer(QString projectPath);
    ~GSSerializer();
    void SaveCurrentFile(QString file);


private:
    QString projectPath;
    QString fileSuffix = ".dfc";
    QString folderName = "deflowAssets/";
    QString folder;
    void SerializeToFile(QFile* file);
};

#endif // GSSERIALIZER_H
