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
    //SaveCurrentFile("placeHolderName");
}

GSSerializer::~GSSerializer()
{

}
void GSSerializer::SaveCurrentFile(QString fileName)
{
    QFile *file = new QFile(folder + fileName + fileSuffix);

    if(file->open(QIODevice::ReadWrite))
    {
        SerializeToFile(file);
        file->close();
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
            graphSpaceObj.insert("Block_" + QString::number(j), Canvas::instance->GetGraphSpaces()[i]->blocks[j]->GetJsonRepresentation());
        }
        canvasObj.insert(Canvas::instance->GetGraphSpaces()[i]->objectName(), graphSpaceObj);
    }
    file->write(QJsonDocument(canvasObj).toJson());

}
