#include "getscaleblock.h"
#include "ui_getscaleblock.h"

GetScaleBlock::GetScaleBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::GetScaleBlock)
{
    ui->setupUi(this);
    initConnectors();
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    myType = BaseBlock::BlockType::GetScaleBlock;
}

GetScaleBlock::~GetScaleBlock()
{
    delete ui;
}
QString GetScaleBlock::getLuaCodeLine()
{
    return tr("go.get_scale() \n");
}
