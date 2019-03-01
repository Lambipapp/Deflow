#include "subtractblock.h"
#include "ui_subtractblock.h"

SubtractBlock::SubtractBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::SubtractBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::SubtractBlock;
}

SubtractBlock::~SubtractBlock()
{
    delete ui;
}
QString SubtractBlock::getLuaCodeLine()
{
    return QString();
}
QJsonObject SubtractBlock::GetJsonRepresentation()
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
void SubtractBlock::ReLoadData(QJsonObject data)
{
    QJsonValue pos = data.value(tr("Position"));
    move(posFromjsv(pos));
    //SET POSITION
    //SET CONNECTORIDS
    //SET CONNECTIONS
}
