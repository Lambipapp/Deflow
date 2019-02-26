#include "stringblock.h"
#include "ui_stringblock.h"

StringBlock::StringBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::StringBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
}

StringBlock::~StringBlock()
{
    delete ui;
}

QString StringBlock::getLuaCodeLine()
{
    return QString();
}
