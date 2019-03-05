#include "constantvarblock.h"
#include "ui_constantvarblock.h"

ConstantVarBlock::ConstantVarBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::ConstantVarBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::ConstantVarBlock;
}

ConstantVarBlock::~ConstantVarBlock()
{
    delete ui;
}
QString ConstantVarBlock::getLuaCodeLine()
{

    //if ui->lineEdit->text() contains other than numbers (or decimals), add quotes to make it a string, else return as a number

    return ui->lineEdit->text();
}


