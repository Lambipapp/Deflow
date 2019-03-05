#include "loopblock.h"
#include "ui_loopblock.h"

LoopBlock::LoopBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::LoopBlock)
{
    ui->setupUi(this);
    initConnectors();
    for(uint i = 0; i < myExecOutConnectors.size(); i++)
    {
        if(myExecOutConnectors[i] == ui->LoopOut)
        {
            myExecOutConnectors.erase(myExecOutConnectors.begin() + i);
        }
    }
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    myType = BaseBlock::BlockType::LoopBlock;
}

LoopBlock::~LoopBlock()
{
    delete ui;
}
QString LoopBlock::getLuaCodeLine()
{
    QString codeLine;
    QString val;
    val = ui->Node->input->myBlock->getLuaCodeLine();



    codeLine = "for i = 1," + val + ", 1 do\n";

    //add blocks to loop
    std::vector<BaseBlock*> discovered;

    discovered.push_back(this->ui->LoopOut->next->myBlock);


    BaseBlock* current;
    while(discovered.size() > 0)
    {
        current = discovered.back();
        discovered.pop_back();


        if(current)
        {
            codeLine += current->getLuaCodeLine() + "\n";

            for(uint i = 0; i < current->myExecOutConnectors.size(); i++)
            {
                if(current->myExecOutConnectors[i]->next)
                    discovered.push_back(current->myExecOutConnectors[i]->next->myBlock);
            }
        }
    }




    //add end
    codeLine += "\nend\n";
    return codeLine;



}

