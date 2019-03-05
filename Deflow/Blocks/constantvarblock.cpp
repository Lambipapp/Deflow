#include "constantvarblock.h"
#include "ui_constantvarblock.h"

ConstantVarBlock::ConstantVarBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::ConstantVarBlock)
{
    ui->setupUi(this);
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();
    myType = BaseBlock::BlockType::ConstantVarBlock;
}

ConstantVarBlock::~ConstantVarBlock()
{
    delete ui;
}
QString ConstantVarBlock::getLuaCodeLine()
{

    //if ui->lineEdit->text() contains other than numbers (or decimals), add quotes to make it a string, else return as a number

    QString constant = ui->lineEdit->text();

    if(constant.toLower() == "true" || constant.toLower() == "false")
        constant = constant.toLower();

    else if(!isDigits(constant))
    {
        constant = "\"" + constant + "\"";
    }

    return constant;
}


bool ConstantVarBlock::isDigits(const QString &string) const
{
    return string.toStdString().find_first_not_of("0123456789.,") == std::string::npos;
}

