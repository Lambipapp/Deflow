#include "inputblock.h"
#include "ui_inputblock.h"
#include "filemanager.h"

InputBlock::InputBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::InputBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::InputBlock;
    ui->actionTypeBox->addItem(QString("On Pressed"));  //action.pressed
    ui->actionTypeBox->addItem(QString("On Held"));     //action.repeated       //double check if this one works
    ui->actionTypeBox->addItem(QString("On Released")); //action.released
    FileManager::fm->FindAndReadInputFile(inputFileContents);
    InputKeys = InterpretInputFileContents();
    SetActionBoxContent(InputKeys);

    //TODO: uncomment line above, interpret the content, update the dropdown list

}

InputBlock::~InputBlock()
{
    delete ui;
}
QString InputBlock::getLuaCodeLine()
{
    return QString();
}
QJsonObject InputBlock::GetJsonRepresentation()
{
    QJsonObject pos;
    pos.insert("x", this->pos().x());
    pos.insert("y", this->pos().y());
    QJsonObject data;
    data.insert("Position", pos);
    data.insert("Connectors", ParseConnectors());
    QJsonObject o;
    o.insert(QString::number(myType), data);

    return o;
}
void InputBlock::ReLoadData(QJsonObject data)
{
    QJsonValue pos = data.value(tr("Position"));
    move(posFromjsv(pos));
    //SET POSITION
    //SET CONNECTORIDS
    //SET CONNECTIONS
}

QStringList InputBlock::InterpretInputFileContents()
{
    if(inputFileContents == "")
        return QStringList();

    QRegExp rx("\\n");
    QStringList query = inputFileContents.split(rx);

    QStringList actions;
    for(int i = 0; i < query.size(); i++)
    {
        //i dont know what this does. but it works so i dont care
        if(query[i].contains("action:"))
        {
            QRegExp rx2("action:|\\\"");
            QStringList tmp = query[i].split(rx2);
            actions.push_back(tmp[2]);
        }
    }
    return actions;
}

void InputBlock::SetActionBoxContent(const QStringList &inputKeys)
{
    ui->ActionNameBox->clear();
    if(inputKeys.size() == 0)
    {
        ui->ActionNameBox->addItem("No Input Keys Detected");
    }

    ui->ActionNameBox->addItems(inputKeys);
}



void InputBlock::on_ActionNameBox_activated(const QString &arg1)
{
    qDebug() << "test";
}
