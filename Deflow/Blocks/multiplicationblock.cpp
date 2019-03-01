#include "multiplicationblock.h"
#include "ui_multiplicationblock.h"

MultiplicationBlock::MultiplicationBlock(QWidget *parent) :
    BaseBlock (parent),
    ui(new Ui::MultiplicationBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::MultiplicationBlock;
}

MultiplicationBlock::~MultiplicationBlock()
{
    delete ui;
}
QString MultiplicationBlock::getLuaCodeLine()
{
    return QString();
}
QJsonObject MultiplicationBlock::GetJsonRepresentation()
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
void MultiplicationBlock::ReLoadData(QJsonObject data)
{
    QJsonValue pos = data.value(tr("Position"));
    move(posFromjsv(pos));
    //SET POSITION
    //SET CONNECTORIDS
    //SET CONNECTIONS
}
