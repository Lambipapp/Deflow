#include "stringblock.h"
#include "ui_stringblock.h"

StringBlock::StringBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::StringBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BlockType::StringBlock;
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
    o.insert(QString::number(myType), data);

    return o;
}
void StringBlock::ReLoadData(QJsonObject data)
{
    QJsonValue pos = data.value(tr("Position"));
    move(posFromjsv(pos));
    //SET POSITION
    //SET CONNECTORIDS
    //SET CONNECTIONS
}
