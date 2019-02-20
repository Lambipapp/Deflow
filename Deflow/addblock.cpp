#include "addblock.h"
#include "ui_addblock.h"

AddBlock::AddBlock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddBlock)
{
    ui->setupUi(this);
}

AddBlock::~AddBlock()
{
    delete ui;
}
