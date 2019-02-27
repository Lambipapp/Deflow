#include "gsserializer.h"
#include <vector>

GSSerializer::GSSerializer(QString ProjectPath) :
    projectPath(ProjectPath)
{
    if(QDir(projectPath + folderName).exists())
    {
        folder = projectPath + folderName;

    }
    else
    {
        if(QDir().mkdir(projectPath + folderName))
            folder = projectPath + folderName;
    }
    SaveCurrentFile("placeHolderName");
    LoadFromFile("placeHolderName");

}

GSSerializer::~GSSerializer()
{

}
void GSSerializer::SaveCurrentFile(QString fileName)
{
    QFile *file = new QFile(folder + fileName + fileSuffix);

    if(file->open(QIODevice::WriteOnly))
    {
        SerializeToFile(file);

    }
}
void GSSerializer::SerializeToFile(QFile *file)
{
    file->resize(0);
    QJsonObject canvasObj;
    for(int i = 0; i < Canvas::instance->GetGraphSpaces().size(); i++)
    {
        QJsonObject graphSpaceObj;
        for(unsigned int j = 0; j < Canvas::instance->GetGraphSpaces()[i]->blocks.size(); j++)
        {
            graphSpaceObj.insert("Block_" + QString::number(j+1), Canvas::instance->GetGraphSpaces()[i]->blocks[j]->GetJsonRepresentation());
        }
        canvasObj.insert(Canvas::instance->GetGraphSpaces()[i]->objectName(), graphSpaceObj);
    }
    file->write(QJsonDocument(canvasObj).toJson());
    file->close();
    delete file;

}

void GSSerializer::LoadFromFile(QString scriptName)
{
    QFile *file = new QFile(folder + scriptName + fileSuffix);
    if(file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ParseSaveFile(file);
    }
}

void GSSerializer::ParseSaveFile(QFile*file)
{
    QString fileData = file->readAll();
    file->close();
    delete file;

    QJsonDocument jsondoc = QJsonDocument::fromJson(fileData.toUtf8());

    QJsonObject c = jsondoc.object();

    QJsonObject finalC      = c.value(QString("FinalCanvas"))    .toObject();
    QJsonObject initC       = c.value(QString("InitCanvas"))     .toObject();
    QJsonObject inputC      = c.value(QString("OnInputCanvas"))  .toObject();
    QJsonObject msgC        = c.value(QString("OnMessageCanvas")).toObject();
    QJsonObject rlC         = c.value(QString("OnReloadCanvas")) .toObject();
    QJsonObject updateC     = c.value(QString("UpdateCanvas"))   .toObject();


    for(int i = 0; i < 6; i++)
    {
        QJsonObject o = i == 0 ? initC : ( i == 1 ? updateC :( i == 2 ? msgC : ( i == 3 ? inputC : ( i == 4? rlC : finalC))));
        for(QJsonObject::iterator j = o.begin(); j != o.end(); j++)
        {
            int bt = j.value().toObject().begin().key().toInt();
            QJsonObject bData = j.value().toObject().begin().value().toObject();
            //qDebug() << bData;
            auto *b = Canvas::instance->GetGraphSpaces().at(i)->CreateBlock(bt);
            b->ReLoadData(bData);
        }
    }
}
