#include "acquireinputblock.h"
#include "ui_acquireinputblock.h"

AcquireInputBlock::AcquireInputBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::AcquireInputBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BlockType::AcquireInputBlock;
}

AcquireInputBlock::~AcquireInputBlock()
{
    delete ui;
}
QString AcquireInputBlock::getLuaCodeLine()
{

    return ui->checkBox->isChecked() == true ? "msg.post(\".\", \"acquire_input_focus\")" : "msg.post(\".\", \"release_input_focus\")";
}


