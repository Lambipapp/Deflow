#include "divisionblock.h"
#include "ui_divisionblock.h"

DivisionBlock::DivisionBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::DivisionBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::DivisionBlock;
}

DivisionBlock::~DivisionBlock()
{
    delete ui;
}
QString DivisionBlock::getLuaCodeLine()
{
    return QString();
}
QJsonObject DivisionBlock::GetJsonRepresentation()
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
void DivisionBlock::ReLoadData(QJsonObject data)
{
    QJsonValue pos = data.value(tr("Position"));
    move(posFromjsv(pos));
    //SET POSITION
    //SET CONNECTORIDS
    //SET CONNECTIONS
}
