#include "vectorconstantblock.h"
#include "ui_vectorconstantblock.h"

VectorConstantBlock::VectorConstantBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::VectorConstantBlock)
{
    ui->setupUi(this);
    initConnectors();
    myType = BaseBlock::BlockType::VectorConstantBlock;
    ui->label->setAttribute(Qt::WA_TransparentForMouseEvents);
}

VectorConstantBlock::~VectorConstantBlock()
{
    delete ui;
}
QString VectorConstantBlock::getLuaCodeLine()
{
    QString vector = "vmath.vector3(";
    vector += ui->x_field->text() + ",";
    vector += ui->y_field->text() + ",";
    vector += ui->z_field->text() + ")";
    return vector;
}
