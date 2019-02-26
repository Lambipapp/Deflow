#include "gsserializer.h"


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
}

GSSerializer::~GSSerializer()
{

}
void GSSerializer::SaveCurrentFile(QString fileName)
{
    QFile *file = new QFile(folder + fileName + fileSuffix);

    if(file->open(QIODevice::ReadWrite))
    {
        qDebug() << "Opened: " << *file;
        SerializeToFile(file);
        file->close();
    }
}
void GSSerializer::SerializeToFile(QFile *file)
{


}
