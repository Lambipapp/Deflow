#include "setvarblock.h"
#include "ui_setvarblock.h"

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

    return QString();
   //return "local " + ui->NameField->toPlainText() + " = " + ui->ValueField->toPlainText();
}


