#include "inputblock.h"
#include "ui_inputblock.h"

InputBlock::InputBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::InputBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::InputBlock;
    ui->actionTypeBox->addItem(QString("On Pressed"));  //action.pressed
    ui->actionTypeBox->addItem(QString("On Held"));     //action.repeated       //double check if this one works
    ui->actionTypeBox->addItem(QString("On Released")); //action.released
    ui->ActionNameBox->myBlock = this;

}

InputBlock::~InputBlock()
{
    delete ui;
}
QString InputBlock::getLuaCodeLine()
{
    return QString();
}



void InputBlock::UpdateActionNameBox()
{
    ui->ActionNameBox->UpdateContents();
}

void InputBlock::mousePressEvent(QMouseEvent* event)
{
    BaseBlock::mousePressEvent(event);
}


void InputBlock::on_ActionNameBox_activated(const QString &arg1)
{
    qDebug() << "test";
}
