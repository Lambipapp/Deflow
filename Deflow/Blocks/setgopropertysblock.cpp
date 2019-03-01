#include "setgopropertysblock.h"
#include "ui_setgopropertysblock.h"

SetGOPropertysBlock::SetGOPropertysBlock(QWidget *parent) :
    BaseBlock (parent),
    ui(new Ui::SetGOPropertysBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::SetGOPropertysBlock;
}

SetGOPropertysBlock::~SetGOPropertysBlock()
{
    delete ui;
}
QString SetGOPropertysBlock::getLuaCodeLine()
{
return QString();
}
QJsonObject SetGOPropertysBlock::GetJsonRepresentation()
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
void SetGOPropertysBlock::ReLoadData(QJsonObject data)
{
    QJsonValue pos = data.value(tr("Position"));
    move(posFromjsv(pos));
    //SET POSITION
    //SET CONNECTORIDS
    //SET CONNECTIONS
}
