#include "setvarblock.h"
#include "ui_setvarblock.h"
#include "newvarblock.h"

SetVarBlock::SetVarBlock(QWidget *parent) :
    BaseBlock (parent),
    ui(new Ui::SetVarBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::SetVarBlock;
    ui->VarSelector->myBlock = this;
}

SetVarBlock::~SetVarBlock()
{
    delete ui;
}
QString SetVarBlock::getLuaCodeLine()
{
    return "self." + ui->VarSelector->currentText() + " = " + ui->VarNode->input->myBlock->getLuaCodeLine() + "\n";
}

QStringList SetVarBlock::UpdateComboBoxContents()
{
//    QStringList content;
//    content.clear();
//    std::vector<BaseBlock*> discovered;


//    discovered.push_back(this);



//    BaseBlock* current = nullptr;
//    while(discovered.size() > 0)
//    {
//        current = discovered[discovered.size()-1];
//        discovered.pop_back();
//        class NewVarBlock* nvb = dynamic_cast<class NewVarBlock*>(current);
//        if(nvb)
//        {
//            content.push_back(nvb->GetVarName());
//        }


//        if(current->myExecInConnector)
//        {
//            if(current->myExecInConnector->myBlock)
//            {
//                for(uint i = 0; i < current->myExecInConnector->connected.size(); i++)
//                {
//                    discovered.push_back(current->myExecInConnector->connected[i]->myBlock);
//                }
//            }
//        }
//    }



//    if(!(Canvas::currentGraphSpace == Canvas::instance->GetGraphSpaces().at(0))) //hardcoded becuase why not. no time to make good code :):):):):)
//    {
//        discovered.clear();
//        BaseBlock* current = nullptr;

//        discovered.push_back(Canvas::instance->GetGraphSpaces().at(0)->startBlock);

//        while(discovered.size() > 0)
//        {
//            current = discovered.back();
//            discovered.pop_back();
//            class NewVarBlock* nvb = dynamic_cast<class NewVarBlock*>(current);
//            if(nvb)
//            {
//                content.push_back(nvb->GetVarName());
//            }
//            for(uint i = 0; i < current->myExecOutConnectors.size(); i++)
//            {
//                if(current->myExecOutConnectors[i]->next)
//                {
//                    discovered.push_back(current->myExecOutConnectors[i]->next->myBlock);
//                }
//            }
//        }
//    }
//    return content;

    return Canvas::instance->GetAllVariables();


}



