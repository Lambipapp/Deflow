#include "stringblock.h"
#include "ui_stringblock.h"

StringBlock::StringBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::StringBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
}

StringBlock::~StringBlock()
{
    delete ui;
}

QString StringBlock::getLuaCodeLine()
{
    return QString();
}

QJsonObject StringBlock::GetJsonRepresentation()
{
    QJsonObject pos;
    pos.insert("x", this->pos().x());
    pos.insert("y", this->pos().y());
    QJsonObject data;
    data.insert("Position", pos);
    data.insert("Connectors", ParseConnectors());
    QJsonObject o;
    o.insert("StringBlock", data);

    return o;
}
