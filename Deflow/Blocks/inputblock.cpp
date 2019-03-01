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
    //FileManager::fm->FindAndReadInputFile()
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

void InputBlock::on_ActionNameBox_activated(const QString &arg1)
{
    qDebug() << "test";
}

void InputBlock::on_ActionNameBox_highlighted(const QString &arg1)
{
    qDebug() << "test2";
}
