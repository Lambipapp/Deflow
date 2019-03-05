#include "subtractblock.h"
#include "ui_subtractblock.h"

SubtractBlock::SubtractBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::SubtractBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::SubtractBlock;
}

SubtractBlock::~SubtractBlock()
{
    delete ui;
}
QString SubtractBlock::getLuaCodeLine()
{
    return QString();
}

