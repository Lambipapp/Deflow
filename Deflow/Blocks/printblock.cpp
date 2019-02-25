#include "printblock.h"
#include "ui_printblock.h"

PrintBlock::PrintBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::PrintBlock)
{
    ui->setupUi(this);
    initConnectors();
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
}

PrintBlock::~PrintBlock()
{
    delete ui;
}

QString PrintBlock::getLuaCodeLine()
{
    return tr("");
}
