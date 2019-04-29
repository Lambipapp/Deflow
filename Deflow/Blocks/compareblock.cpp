#include "compareblock.h"
#include "ui_compareblock.h"

CompareBlock::CompareBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::CompareBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BlockType::CompareBlock;
    ui->VarBox->addItem("<");
    ui->VarBox->addItem(">");
    ui->VarBox->addItem("==");
    ui->VarBox->addItem("!=");
}

CompareBlock::~CompareBlock()
{
    delete ui;
}
QString CompareBlock::getLuaCodeLine()
{
    return "true";
}
