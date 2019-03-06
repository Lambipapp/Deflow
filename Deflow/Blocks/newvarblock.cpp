#include "newvarblock.h"
#include "ui_newvarblock.h"

NewVarBlock::NewVarBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::NewVarBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BlockType::NewVarBlock;



    //IF CREATED IN INIT TAB STRING IS "self.varName"
    //IF CREATED IN ANY OTHER TAB STRING IS "local varName"
}

NewVarBlock::~NewVarBlock()
{
    delete ui;
}
QString NewVarBlock::getLuaCodeLine()
{
    if(ui->ValueNode->input)
        return "self." + ui->NameField->text() + " = " + ui->ValueNode->input->myBlock->getLuaCodeLine();
    return "self." + ui->NameField->text() + " = nil";
}



QString NewVarBlock::GetVarName() const
{
    return ui->NameField->text();
}

