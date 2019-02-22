#include "startblock.h"
#include "ui_startblock.h"

StartBlock::StartBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::StartBlock)
{
    ui->setupUi(this);
    connectorsOUT.push_back(ui->Node_3);

}


StartBlock::~StartBlock()
{
    delete ui;
}

QString StartBlock::getLuaCodeLine()
{
return QString();
}
