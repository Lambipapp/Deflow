#include "autoupdatecombobox.h"
#include "ui_autoupdatecombobox.h"


AutoUpdateComboBox::AutoUpdateComboBox(QWidget *parent) :
    QComboBox(parent),
    ui(new Ui::AutoUpdateComboBox)
{
    ui->setupUi(this);
    //UpdateContents();
}

AutoUpdateComboBox::~AutoUpdateComboBox()
{
    delete ui;
}


void AutoUpdateComboBox::showPopup()
{
    UpdateContents();
    QComboBox::showPopup();
}


void AutoUpdateComboBox::UpdateContents()
{
    switch(myBlock->myType)
    {
    case BaseBlock::BlockType::InputBlock:
        UpdateComboBoxWithInputFile();
        break;
    case BaseBlock::BlockType::SetVarBlock:
        UpdateComboBoxWithVariables();
        break;

    default:
        break;
    }
}


void AutoUpdateComboBox::UpdateComboBoxWithVariables()
{
    content.clear();
    std::vector<BaseBlock*> discovered;


    discovered.push_back(this->myBlock);



    BaseBlock* current = nullptr;
    while(discovered.size() > 0)
    {
        current = discovered[discovered.size()-1];
        discovered.pop_back();
        NewVarBlock* nvb = dynamic_cast<NewVarBlock*>(current);
        if(nvb)
        {
            content.push_back(nvb->GetVarName());
        }


        if(current->myExecInConnector)
        {
            if(current->myExecInConnector->myBlock)
            {
                for(uint i = 0; i < current->myExecInConnector->connected.size(); i++)
                {
                    discovered.push_back(current->myExecInConnector->connected[i]->myBlock);
                }
            }
        }


    }



    if(!(Canvas::currentGraphSpace == Canvas::instance->GetGraphSpaces().at(0))) //hardcoded becuase why not. no time to make good code :):):):):)
    {
        discovered.clear();
        BaseBlock* current = nullptr;

        discovered.push_back(Canvas::instance->GetGraphSpaces().at(0)->startBlock);

        while(discovered.size() > 0)
        {
            current = discovered.back();
            discovered.pop_back();
            NewVarBlock* nvb = dynamic_cast<NewVarBlock*>(current);
            if(nvb)
            {
                content.push_back(nvb->GetVarName());
            }
            for(uint i = 0; i < current->myExecOutConnectors.size(); i++)
            {
                if(current->myExecOutConnectors[i]->next)
                {
                    discovered.push_back(current->myExecOutConnectors[i]->next->myBlock);
                }
            }
        }
    }
    SetActionBoxContent(content);

}


void AutoUpdateComboBox::UpdateComboBoxWithInputFile()
{
    FileManager::fm->FindAndReadInputFile(inputFileContents);
    content = InterpretInputFileContents();
    SetActionBoxContent(content);
}



QStringList AutoUpdateComboBox::InterpretInputFileContents()
{
    if(inputFileContents == "")
        return QStringList();

    QRegExp rx("\\n");
    QStringList query = inputFileContents.split(rx);

    QStringList actions;
    for(int i = 0; i < query.size(); i++)
    {
        //i dont know what this does. but it works so i dont care
        if(query[i].contains("action:"))
        {
            QRegExp rx2("action:|\\\"");
            QStringList tmp = query[i].split(rx2);
            actions.push_back(tmp[2]);
        }
    }
    return actions;
}


void AutoUpdateComboBox::SetActionBoxContent(const QStringList &inputKeys)
{
    clear();
    if(inputKeys.size() == 0)
    {
        addItem("No Input Keys Detected");
    }

    addItems(inputKeys);
}
