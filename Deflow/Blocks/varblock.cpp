#include "varblock.h"
#include "ui_varblock.h"

VarBlock::VarBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::VarBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BlockType::VarBlock;
    ui->VarBox->addItem(tr("dt"));
    ui->VarBox->myBlock = this;
}

VarBlock::~VarBlock()
{
    delete ui;
}
QString VarBlock::getLuaCodeLine()
{
    return "";
}

