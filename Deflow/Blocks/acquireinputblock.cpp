#include "acquireinputblock.h"
#include "ui_acquireinputblock.h"

AcquireInputBlock::AcquireInputBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::AcquireInputBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
}

AcquireInputBlock::~AcquireInputBlock()
{
    delete ui;
}
QString AcquireInputBlock::getLuaCodeLine()
{
    return QString();
}

