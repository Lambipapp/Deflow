#include "addblock.h"
#include "ui_addblock.h"

AddBlock::AddBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::AddBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
}

AddBlock::~AddBlock()
{
    delete ui;
}
QString AddBlock::getLuaCodeLine()
{
    return QString();
}
QJsonObject AddBlock::GetJsonRepresentation()
{
    QJsonObject pos;
    pos.insert("x", this->pos().x());
    pos.insert("y", this->pos().y());
    QJsonObject data;
    data.insert("Position", pos);
    data.insert("Connectors", ParseConnectors());
    QJsonObject o;
    o.insert("AddBlock", data);

    return o;
}
