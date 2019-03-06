#include "subtractblock.h"
#include "ui_subtractblock.h"

SubtractBlock::SubtractBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::SubtractBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::SubtractBlock;
}

SubtractBlock::~SubtractBlock()
{
    delete ui;
}
QString SubtractBlock::getLuaCodeLine()
{
    QString codeLine;

   if(ui->a_Node->input)
       codeLine = ui->a_Node->input->myBlock->getLuaCodeLine();
   else
       codeLine = "0";

   codeLine += " - ";

   if(ui->b_Node->input)
       codeLine += ui->b_Node->input->myBlock->getLuaCodeLine();
   else
       codeLine += "0";

   codeLine += "\n";

   return codeLine;
}

