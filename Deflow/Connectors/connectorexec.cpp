#include "connectorexec.h"
#include "ui_connectorexec.h"

ConnectorExec::ConnectorExec(QWidget *parent) :
    Connector(parent),
    ui(new Ui::ConnectorExec)
{

    ui->setupUi(this);
}

ConnectorExec::~ConnectorExec()
{
    delete ui;
}
