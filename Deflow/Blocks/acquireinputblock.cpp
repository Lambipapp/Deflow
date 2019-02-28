#include "acquireinputblock.h"
#include "ui_acquireinputblock.h"

AcquireInputBlock::AcquireInputBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::AcquireInputBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BlockType::AcquireInputBlock;
}

AcquireInputBlock::~AcquireInputBlock()
{
    delete ui;
}
QString AcquireInputBlock::getLuaCodeLine()
{

    return ui->checkBox->isChecked() == true ? "msg.post(\".\", \"acquire_input_focus\")" : "msg.post(\".\", \"release_input_focus\")";
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
    o.insert(QString::number(myType), data);

    return o;
}
void AcquireInputBlock::ReLoadData(QJsonObject data)
{
    QJsonValue pos = data.value(tr("Position"));
    move(posFromjsv(pos));
    //SET POSITION
    //SET CONNECTORIDS
    //SET CONNECTIONS
}

