#include "getgopropertysblock.h"
#include "ui_getgopropertysblock.h"

GetGOPropertysBlock::GetGOPropertysBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::GetGOPropertysBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BlockType::GetGOPropertysBlock;
}

GetGOPropertysBlock::~GetGOPropertysBlock()
{
    delete ui;
}

QString GetGOPropertysBlock::getLuaCodeLine()
{
return QString();
}
QJsonObject GetGOPropertysBlock::GetJsonRepresentation()
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
void GetGOPropertysBlock::ReLoadData(QJsonObject data)
{
    QJsonValue pos = data.value(tr("Position"));
    move(posFromjsv(pos));
    //SET POSITION
    //SET CONNECTORIDS
    //SET CONNECTIONS
}
