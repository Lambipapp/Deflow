#include "acquireinputblock.h"
#include "ui_acquireinputblock.h"

AcquireInputBlock::AcquireInputBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::AcquireInputBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
}

AcquireInputBlock::~AcquireInputBlock()
{
    delete ui;
}
QString AcquireInputBlock::getLuaCodeLine()
{
    return QString();
}
QJsonObject AcquireInputBlock::GetJsonRepresentation()
{
    QJsonObject pos;
    pos.insert("x", this->pos().x());
    pos.insert("y", this->pos().y());
    QJsonObject data;
    data.insert("Position", pos);
    data.insert("Connectors", ParseConnectors());
    QJsonObject o;
    o.insert("AcquireInputBlock", data);

    return o;
}

