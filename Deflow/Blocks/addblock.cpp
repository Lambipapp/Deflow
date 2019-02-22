#include "addblock.h"
#include "ui_addblock.h"

AddBlock::AddBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::AddBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    connectorsIN.push_back(ui->Node);
    connectorsIN.push_back(ui->Node_2);
    connectorsOUT.push_back(ui->Node_3);
}

AddBlock::~AddBlock()
{
    delete ui;
}
QString AddBlock::getLuaCodeLine()
{

    return QString();
}
