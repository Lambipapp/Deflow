#include "addblock.h"
#include "ui_addblock.h"

AddBlock::AddBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::AddBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BlockType::AddBlock;
}

AddBlock::~AddBlock()
{
    delete ui;
}
QString AddBlock::getLuaCodeLine()
{
    QString codeLine;

   if(ui->Node->input)
       codeLine = ui->Node->input->myBlock->getLuaCodeLine();
   else
       codeLine = "0";

   codeLine += " + ";

   if(ui->Node_2->input)
       codeLine += ui->Node_2->input->myBlock->getLuaCodeLine();
   else
       codeLine += "0";

   codeLine += "\n";

   return codeLine;
}
