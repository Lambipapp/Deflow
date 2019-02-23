#include "connectorin.h"
#include "ui_connectorin.h"

ConnectorIn::ConnectorIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectorIn)
{
    ui->setupUi(this);
}

ConnectorIn::~ConnectorIn()
{
    delete ui;
}
