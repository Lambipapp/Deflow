#include "connectorexecout.h"
#include "connectorexecin.h"
#include "ui_connectorexecout.h"

ConnectorExecOut::ConnectorExecOut(QWidget *parent) :
    Connector(parent),
    ui(new Ui::ConnectorExecOut)
{
    ui->setupUi(this);
    myType = NodeType::execOut;
    ui->Arrow->setAttribute(Qt::WA_TransparentForMouseEvents);
}

ConnectorExecOut::~ConnectorExecOut()
{
    delete ui;
}
void ConnectorExecOut::mousePressEvent(QMouseEvent *event)
{

}
void ConnectorExecOut::mouseReleaseEvent(QMouseEvent* event)
{
    QWidget* widget = qApp->widgetAt(event->globalPos());

    if(widget == this)
        return;

    if(widget->inherits("Connector"))
    {
        Connector* temp = static_cast<Connector*>(widget);

        if(temp->myType == NodeType::execIn)
        {
            if(temp->myBlock == myBlock)
                return;

            ConnectorExecIn* c = static_cast<ConnectorExecIn*>(widget);
            next = c;

        }
    }
}
void ConnectorExecOut::mouseMoveEvent(QMouseEvent *event)
{

}
