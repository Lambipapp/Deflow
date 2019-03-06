#include "divisionblock.h"
#include "ui_divisionblock.h"

DivisionBlock::DivisionBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::DivisionBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::DivisionBlock;
}

DivisionBlock::~DivisionBlock()
{
    delete ui;
}
QString DivisionBlock::getLuaCodeLine()
{
    QString codeLine;

   if(ui->a_Node->input)
       codeLine = ui->a_Node->input->myBlock->getLuaCodeLine();
   else
       codeLine = "1";

   codeLine += " / ";

   if(ui->b_Node->input)
       codeLine += ui->b_Node->input->myBlock->getLuaCodeLine();
   else
       codeLine += "1";

   codeLine += "\n";

   return codeLine;
}

