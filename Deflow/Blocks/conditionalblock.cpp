#include "conditionalblock.h"
#include "ui_conditionalblock.h"

ConditionalBlock::ConditionalBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::ConditionalBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BlockType::ConditionalBlock;
}

ConditionalBlock::~ConditionalBlock()
{
    delete ui;
}
QString ConditionalBlock::getLuaCodeLine()
{
    return QString();
}


