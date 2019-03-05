#include "getgopropertysblock.h"
#include "ui_getgopropertysblock.h"

GetGOPropertysBlock::GetGOPropertysBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::GetGOPropertysBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BlockType::GetGOPropertysBlock;
}

GetGOPropertysBlock::~GetGOPropertysBlock()
{
    delete ui;
}

QString GetGOPropertysBlock::getLuaCodeLine()
{
return QString();
}

