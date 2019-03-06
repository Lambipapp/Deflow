#include "multiplicationblock.h"
#include "ui_multiplicationblock.h"

MultiplicationBlock::MultiplicationBlock(QWidget *parent) :
    BaseBlock (parent),
    ui(new Ui::MultiplicationBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::MultiplicationBlock;
}

MultiplicationBlock::~MultiplicationBlock()
{
    delete ui;
}
QString MultiplicationBlock::getLuaCodeLine()
{
    QString codeLine;

   if(ui->a_Node->input)
       codeLine = ui->a_Node->input->myBlock->getLuaCodeLine();
   else
       codeLine = "1";

   codeLine += " * ";

   if(ui->b_Node->input)
       codeLine += ui->b_Node->input->myBlock->getLuaCodeLine();
   else
       codeLine += "1";

   codeLine += "\n";

   return codeLine;
}

