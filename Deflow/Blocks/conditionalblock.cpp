#include "conditionalblock.h"
#include "ui_conditionalblock.h"

ConditionalBlock::ConditionalBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::ConditionalBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
}

ConditionalBlock::~ConditionalBlock()
{
    delete ui;
}
QString ConditionalBlock::getLuaCodeLine()
{
    return QString();
}

QJsonObject ConditionalBlock::GetJsonRepresentation()
{
    QJsonObject pos;
    pos.insert("x", this->pos().x());
    pos.insert("y", this->pos().y());
    QJsonObject data;
    data.insert("Position", pos);
    data.insert("Connectors", ParseConnectors());
    QJsonObject o;
    o.insert("ConditionalBlock", data);

    return o;
}
