#include "addblock.h"
#include "ui_addblock.h"

AddBlock::AddBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::AddBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
}

AddBlock::~AddBlock()
{
    delete ui;
}
QString AddBlock::getLuaCodeLine()
{

    return QString();
}
