#include "printblock.h"
#include "ui_printblock.h"

PrintBlock::PrintBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::PrintBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BlockType::PrintBlock;
}

PrintBlock::~PrintBlock()
{
    delete ui;
}

QString PrintBlock::getLuaCodeLine()
{
    QString prevResult;
    if(ui->NodeConnectorIn->input != nullptr)
        prevResult = ui->NodeConnectorIn->input->myBlock->getLuaCodeLine();


    QString outString = tr("local printval = ") + prevResult + tr("\nprint(printval)");

    return outString;
}


