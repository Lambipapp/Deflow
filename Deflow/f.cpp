#include "f.h"
#include "ui_f.h"

F::F(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::F)
{
    ui->setupUi(this);
}

F::~F()
{
    delete ui;
}
