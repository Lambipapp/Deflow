#include "getpositionblock.h"
#include "ui_getpositionblock.h"

GetPositionBlock::GetPositionBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::GetPositionBlock)
{
    ui->setupUi(this);
    initConnectors();
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    myType = BaseBlock::BlockType::GetPositionBlock;
}

GetPositionBlock::~GetPositionBlock()
{
    delete ui;
}

QString GetPositionBlock::getLuaCodeLine()
{
    return tr("go.get_position() \n");
}
