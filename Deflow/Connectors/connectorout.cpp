#include "connectorout.h"
#include "ui_connectorout.h"
#include "connectorin.h"
#include <QDebug>

ConnectorOut::ConnectorOut(QWidget *parent) :
    Connector(parent),
    ui(new Ui::ConnectorOut)
{
    ui->setupUi(this);
    myType = NodeType::varOut;
    ui->Node->setAttribute(Qt::WA_TransparentForMouseEvents);
}

ConnectorOut::~ConnectorOut()
{
    delete ui;
}

void ConnectorOut::mousePressEvent(QMouseEvent *event) {

}
void ConnectorOut::mouseReleaseEvent(QMouseEvent* event)
{
    QWidget* widget = qApp->widgetAt(event->globalPos());

    if(widget == this)
        return;

    if(widget->inherits("Connector"))
    {
        Connector* temp = static_cast<Connector*>(widget);
        if(temp->myType == NodeType::varIn)
        {
            if(temp->myBlock == myBlock)
                return;

            ConnectorIn* c = static_cast<ConnectorIn*>(widget);
            c->input = this;

        }
    }
}
void ConnectorOut::mouseMoveEvent(QMouseEvent *event) {

}
