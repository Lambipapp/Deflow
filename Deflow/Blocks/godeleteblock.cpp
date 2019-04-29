#include "godeleteblock.h"
#include "ui_godeleteblock.h"

GoDeleteBlock::GoDeleteBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::GoDeleteBlock)
{
    ui->setupUi(this);

    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BlockType::GoDeleteBlock;
}

GoDeleteBlock::~GoDeleteBlock()
{
    delete ui;
}

QString GoDeleteBlock::getLuaCodeLine()
{

   return "go.delete()";
}
