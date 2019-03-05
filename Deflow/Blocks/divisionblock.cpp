#include "divisionblock.h"
#include "ui_divisionblock.h"

DivisionBlock::DivisionBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::DivisionBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::DivisionBlock;
}

DivisionBlock::~DivisionBlock()
{
    delete ui;
}
QString DivisionBlock::getLuaCodeLine()
{
    return QString();
}

