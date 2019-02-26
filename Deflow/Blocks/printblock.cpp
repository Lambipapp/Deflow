#include "printblock.h"
#include "ui_printblock.h"

PrintBlock::PrintBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::PrintBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
}

PrintBlock::~PrintBlock()
{
    delete ui;
}

QString PrintBlock::getLuaCodeLine()
{
    return tr("");
}

QJsonObject PrintBlock::GetJsonRepresentation()
{
    QJsonObject pos;
    pos.insert("x", this->pos().x());
    pos.insert("y", this->pos().y());
    QJsonObject data;
    data.insert("Position", pos);
    data.insert("Connectors", ParseConnectors());
    QJsonObject o;
    o.insert("PrintBlock", data);

    return o;
}
