#include "inputblock.h"
#include "ui_inputblock.h"
#include <algorithm>

InputBlock::InputBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::InputBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();

    myExecOutConnectors.erase(std::remove(myExecOutConnectors.begin(), myExecOutConnectors.end(), ui->InputTrueExecCon), myExecOutConnectors.end());
    myType = BaseBlock::BlockType::InputBlock;
    ui->actionTypeBox->addItem(QString("On Pressed"));  //action.pressed
    ui->actionTypeBox->addItem(QString("On Held"));     //action.repeated       //double check if this one works
    ui->actionTypeBox->addItem(QString("On Released")); //action.released
    ui->ActionNameBox->myBlock = this;

}

InputBlock::~InputBlock()
{
    delete ui;
}
QString InputBlock::getLuaCodeLine()
{
    QString codeLine;

    codeLine += "if action_id == hash(\"" + ui->ActionNameBox->currentText() + "\") and " + DecodeAction() + " then\n";


    std::vector<BaseBlock*> discovered;

    discovered.push_back(this->ui->InputTrueExecCon->next->myBlock);


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
    codeLine += "end\n";

    return codeLine;
}



QStringList InputBlock::UpdateComboBoxContents()
{
    FileManager::fm->FindAndReadInputFile(inputFileContents);
    return InterpretInputFileContents();
}


QStringList InputBlock::InterpretInputFileContents()
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



QString InputBlock::DecodeAction() const
{
    if(ui->actionTypeBox->currentText() == "On Pressed")
        return "action.pressed";
    else if(ui->actionTypeBox->currentText() == "On Held")
        return "action.repeated";
    else if(ui->actionTypeBox->currentText() == "On Released")
        return "action.released";

    else return QString();
}


void InputBlock::mousePressEvent(QMouseEvent* event)
{
    BaseBlock::mousePressEvent(event);
}


void InputBlock::on_ActionNameBox_activated(const QString &arg1)
{
    qDebug() << "test";
}
