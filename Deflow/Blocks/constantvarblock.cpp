#include "constantvarblock.h"
#include "ui_constantvarblock.h"

ConstantVarBlock::ConstantVarBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::ConstantVarBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::ConstantVarBlock;
}

ConstantVarBlock::~ConstantVarBlock()
{
    delete ui;
}
QString ConstantVarBlock::getLuaCodeLine()
{

    //if ui->lineEdit->text() contains other than numbers (or decimals), add quotes to make it a string, else return as a number

    return QString();
}

QJsonObject ConstantVarBlock::GetJsonRepresentation()
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
void ConstantVarBlock::ReLoadData(QJsonObject data)
{
    QJsonValue pos = data.value(tr("Position"));
    move(posFromjsv(pos));
    //SET POSITION
    //SET CONNECTORIDS
    //SET CONNECTIONS
}
