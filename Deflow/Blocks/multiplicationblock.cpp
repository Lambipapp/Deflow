#include "multiplicationblock.h"
#include "ui_multiplicationblock.h"

MultiplicationBlock::MultiplicationBlock(QWidget *parent) :
    BaseBlock (parent),
    ui(new Ui::MultiplicationBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::MultiplicationBlock;
}

MultiplicationBlock::~MultiplicationBlock()
{
    delete ui;
}
QString MultiplicationBlock::getLuaCodeLine()
{
    return QString();
}

