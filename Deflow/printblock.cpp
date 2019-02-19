#include "printblock.h"
#include "ui_printblock.h"

PrintBlock::PrintBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::PrintBlock)
{
    ui->setupUi(this);
}

PrintBlock::~PrintBlock()
{
    delete ui;
}

QString PrintBlock::getLuaCodeLine()
{
    return "Print(" + ui->TextToPrint->toPlainText() + ");";
}
