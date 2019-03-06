#include "varblock.h"
#include "ui_varblock.h"

VarBlock::VarBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::VarBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BlockType::VarBlock;
    //ui->VarBox->addItem(tr("dt"));
    ui->VarBox->myBlock = this;
}

VarBlock::~VarBlock()
{
    delete ui;
}
QString VarBlock::getLuaCodeLine()
{
    if(ui->VarBox->currentText() == "---")
        return "nil";

    if(ui->VarBox->currentText() == "dt")
        return ui->VarBox->currentText();

    return "self." + ui->VarBox->currentText();
}


QStringList VarBlock::UpdateComboBoxContents()
{
    QStringList list;
    if(Canvas::instance->currentGraphSpace == Canvas::instance->GetGraphSpaces()[1])
        list.push_back("dt");

    list.append(Canvas::instance->GetAllVariables());

    return list;
}
