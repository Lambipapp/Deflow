#include "setgopropertysblock.h"
#include "ui_setgopropertysblock.h"

SetGOPropertysBlock::SetGOPropertysBlock(QWidget *parent) :
    BaseBlock (parent),
    ui(new Ui::SetGOPropertysBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::SetGOPropertysBlock;
}

SetGOPropertysBlock::~SetGOPropertysBlock()
{
    delete ui;
}
QString SetGOPropertysBlock::getLuaCodeLine()
{
return QString();
}

