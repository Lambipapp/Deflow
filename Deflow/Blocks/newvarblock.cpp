#include "newvarblock.h"
#include "ui_newvarblock.h"

NewVarBlock::NewVarBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::NewVarBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BlockType::NewVarBlock;



    //IF CREATED IN INIT TAB STRING IS "self.varName"
    //IF CREATED IN ANY OTHER TAB STRING IS "local varName"
}

NewVarBlock::~NewVarBlock()
{
    delete ui;
}
QString NewVarBlock::getLuaCodeLine()
{
    //if node connected, return that instead of valueField

    return "self." + ui->NameField->text() + " = " + ui->Valuefield->text();
   //return "local " + ui->NameField->toPlainText() + " = " + ui->ValueField->toPlainText();
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
    o.insert(QString::number(myType), data);

    return o;
}
void NewVarBlock::ReLoadData(QJsonObject data)
{
    QJsonValue pos = data.value(tr("Position"));
    move(posFromjsv(pos));
    //SET POSITION
    //SET CONNECTORIDS
    //SET CONNECTIONS
}
