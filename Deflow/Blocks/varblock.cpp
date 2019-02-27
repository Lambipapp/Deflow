#include "varblock.h"
#include "ui_varblock.h"

VarBlock::VarBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::VarBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BlockType::VarBlock;
}

VarBlock::~VarBlock()
{
    delete ui;
}
QString VarBlock::getLuaCodeLine()
{
    return "";
}

QJsonObject VarBlock::GetJsonRepresentation()
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
void VarBlock::ReLoadData(QJsonObject data)
{
    QJsonValue pos = data.value(tr("Position"));
    move(posFromjsv(pos));
    //SET POSITION
    //SET CONNECTORIDS
    //SET CONNECTIONS
}
