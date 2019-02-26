#include "newvarblock.h"
#include "ui_newvarblock.h"

NewVarBlock::NewVarBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::NewVarBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();



    //IF CREATED IN INIT TAB STRING IS "self.varName"
    //IF CREATED IN ANY OTHER TAB STRING IS "local varName"
}

NewVarBlock::~NewVarBlock()
{
    delete ui;
}
QString NewVarBlock::getLuaCodeLine()
{
    return QString();
}

QJsonObject NewVarBlock::GetJsonRepresentation()
{
    QJsonObject pos;
    pos.insert("x", this->pos().x());
    pos.insert("y", this->pos().y());
    QJsonObject data;
    data.insert("Position", pos);
    data.insert("Connectors", ParseConnectors());
    QJsonObject o;
    o.insert("NewVarBlock", data);

    return o;
}
