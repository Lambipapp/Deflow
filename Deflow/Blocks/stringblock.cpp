#include "stringblock.h"
#include "ui_stringblock.h"

StringBlock::StringBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::StringBlock)
{
    ui->setupUi(this);
    initConnectors();
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
}

StringBlock::~StringBlock()
{
    delete ui;
}

QString StringBlock::getLuaCodeLine()
{
    return QString();
}
