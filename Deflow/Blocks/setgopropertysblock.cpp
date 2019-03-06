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
    QString codeLine;

    if(ui->PositionNode->input)
    {
        codeLine += "go.set_position(" + ui->PositionNode->input->myBlock->getLuaCodeLine() + ")\n";
    }

    if(ui->RotationNode->input)
    {
        codeLine += "go.set_rotation(" + ui->RotationNode->input->myBlock->getLuaCodeLine() + ")\n";
    }

    if(ui->ScaleNode->input)
    {
        codeLine = "go.set_scale(" + ui->ScaleNode->input->myBlock->getLuaCodeLine() + ")\n";
    }

    return codeLine;
}

