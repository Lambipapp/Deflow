#include "getvectorelementsblock.h"
#include "ui_getvectorelementsblock.h"

GetVectorElementsBlock::GetVectorElementsBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::GetVectorElementsBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BlockType::GetVectorelEmentsBlock;
}

GetVectorElementsBlock::~GetVectorElementsBlock()
{
    delete ui;
}
QString GetVectorElementsBlock::getLuaCodeLine()
{
    return "";
}
