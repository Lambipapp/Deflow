#include "setvarblock.h"
#include "ui_setvarblock.h"

SetVarBlock::SetVarBlock(QWidget *parent) :
    BaseBlock (parent),
    ui(new Ui::SetVarBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::SetVarBlock;
}

SetVarBlock::~SetVarBlock()
{
    delete ui;
}
QString SetVarBlock::getLuaCodeLine()
{

    return QString();
   //return "local " + ui->NameField->toPlainText() + " = " + ui->ValueField->toPlainText();
}

QJsonObject SetVarBlock::GetJsonRepresentation()
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
void SetVarBlock::ReLoadData(QJsonObject data)
{
    QJsonValue pos = data.value(tr("Position"));
    move(posFromjsv(pos));
    //SET POSITION
    //SET CONNECTORIDS
    //SET CONNECTIONS
}
