#include "connectorout.h"
#include "ui_connectorout.h"

ConnectorOut::ConnectorOut(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectorOut)
{
    ui->setupUi(this);
}

ConnectorOut::~ConnectorOut()
{
    delete ui;
}
