#include "getrotationblock.h"
#include "ui_getrotationblock.h"

GetRotationBlock::GetRotationBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::GetRotationBlock)
{
    ui->setupUi(this);
    initConnectors();
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    myType = BaseBlock::BlockType::GetRotationBlock;
}

GetRotationBlock::~GetRotationBlock()
{
    delete ui;
}
QString GetRotationBlock::getLuaCodeLine()
{
    return tr("go.get_rotation() \n");
}
