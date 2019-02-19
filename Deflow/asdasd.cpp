#include "asdasd.h"
#include "ui_asdasd.h"

asdasd::asdasd(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::asdasd)
{
    ui->setupUi(this);
}

asdasd::~asdasd()
{
    delete ui;
}
