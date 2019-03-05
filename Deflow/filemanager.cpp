#include "filemanager.h"

FileManager* FileManager::fm = nullptr;


FileManager::FileManager()
{
    if(fm == nullptr)
        fm = this;
    else delete this;
    od = new OpeningDialog();
}

FileManager::~FileManager()
{
    delete od;
}


bool FileManager::OpenFile(QString filePath, QString fileName)
{
    if(currentFile.fileName() == filePath)
        return false;

    if(ShouldOpenFile(filePath, fileName))
    {
        if(currentFile.isOpen())
            CloseCurrentFile();

        currentFile.setFileName(filePath); //this function being called setfilename makes no sense
        if(currentFile.open(QFile::ReadWrite))
        {
            if(shouldOverwriteCurrentFile())
                OverwriteCurrentFile();

            OnFileOpen();
            return true;
        }
        else return false;
    }
    else
    {
        return false;
    }
}


bool FileManager::shouldOverwriteCurrentFile()
{
    return overwrite;
}

void FileManager::CloseCurrentFile()
{
    OnFileClose();
    currentFile.flush();
    currentFile.close();
}

void FileManager::OnFileClose()
{
    //make sure the file saves before closing here
}

void FileManager::TranslateAndWriteToCurrentFile()
{
    QString code;
    Translator t;
    code = t.TranslateAllGraphSpaces();
    WriteToCurrentFile(code);
}

void FileManager::WriteToCurrentFile(const QString &code)
{
    if(currentFile.isOpen())
    {
        QTextStream outStream(&currentFile);
        currentFile.resize(0);
        outStream << code.toStdString().c_str();
    }
}


void FileManager::OverwriteCurrentFile()
{
    //overwrite here
    //write --Generated by Deflow--
    //write --scriptname.script
    overwrite = false; //reset overwrite flag
}

void FileManager::OnFileOpen()
{
    //open corrent graphspaces, load block positions and connections here
}


void FileManager::SetProjectPath(const QString path)
{
    projectPath = path;
}



bool FileManager::ShouldOpenFile(QString filePath, QString fileName)
{
    QFile tmpFile;
    tmpFile.setFileName(filePath);//this function being called setFileName makes no sense

    if(!tmpFile.open(QFile::ReadWrite))
    {
        qDebug() << "Did not open";
        return false;
    }
    else
    {
        QTextStream in(&tmpFile);

        QString firstLine = in.readLine(0);

        if(firstLine.contains(("--Generated by Deflow--")))
        {

            tmpFile.flush();
            tmpFile.close();
            return true;
        }
        else
        {
            od->SetFile(fileName);
            od->exec();

            tmpFile.flush();
            tmpFile.close();
            overwrite = od->result();
            return od->result();
        }
    }
}

bool FileManager::FindAndReadInputFile(QString &buffer)
{
    if(projectPath == "")
        return false;
    //find all files of type .input_binding in all subfolders of the projectPath
    QDirIterator it(projectPath ,QStringList() << "*.input_binding", QDir::Files, QDirIterator::Subdirectories);

    //Read Input file and store contents in buffer
    if(it.hasNext())
        return ReadFile(it.next(), buffer);
}

bool FileManager::ReadFile(const QString &path, QString &buffer) const
{
    QFile file(path);
    qDebug() << path;

    if(file.open(QFile::ReadOnly))
    {
        QTextStream inStream(&file);
        buffer = inStream.readAll();

        return true;
    }
    else return false;
}



