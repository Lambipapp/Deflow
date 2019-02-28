#include "printblock.h"
#include "ui_printblock.h"

PrintBlock::PrintBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::PrintBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BlockType::PrintBlock;
}

PrintBlock::~PrintBlock()
{
    delete ui;
}

QString PrintBlock::getLuaCodeLine()
{
    QString prevResult;
    if(ui->NodeConnectorIn->input != nullptr)
        prevResult = static_cast<BaseBlock*>(ui->NodeConnectorIn->input->myBlock)->getLuaCodeLine();


    QString outString = tr("local printval = ") + prevResult + tr("\nprint(printval)");

    return outString;
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
    o.insert(QString::number(myType), data);

    return o;
}
void PrintBlock::ReLoadData(QJsonObject data)
{
    QJsonValue pos = data.value(tr("Position"));
    move(posFromjsv(pos));
    //SET POSITION
    //SET CONNECTORIDS
    //SET CONNECTIONS
}
