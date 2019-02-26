#include "newvarblock.h"
#include "ui_newvarblock.h"

NewVarBlock::NewVarBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::NewVarBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
}

NewVarBlock::~NewVarBlock()
{
    delete ui;
}
QString NewVarBlock::getLuaCodeLine()
{
    return QString();
}
