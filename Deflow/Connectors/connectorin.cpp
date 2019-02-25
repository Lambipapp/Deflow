#include "connectorin.h"
#include "ui_connectorin.h"
#include "canvas.h"

ConnectorIn::ConnectorIn(QWidget *parent) :
    Connector(parent),
    ui(new Ui::ConnectorIn)
{
    ui->setupUi(this);
    myType = NodeType::varIn;
    ui->Node->setAttribute(Qt::WA_TransparentForMouseEvents);
}

ConnectorIn::~ConnectorIn()
{
    input = nullptr;
    delete ui;
}

void ConnectorIn::mousePressEvent(QMouseEvent *event)
{
    clickedConnector = this;
}
void ConnectorIn::mouseReleaseEvent(QMouseEvent* event)
{
    QWidget* widget = qApp->widgetAt(event->globalPos());

    if(widget == this)
        return;

    if(widget->inherits("Connector"))
    {
        Connector* temp = static_cast<Connector*>(widget);
        if(temp->myType == NodeType::varOut)
        {
            if(temp->myBlock == myBlock)
                return;

            ConnectorOut* c = static_cast<ConnectorOut*>(widget);
            input = c;
        }
    }
    Canvas::lineRenderer->update();
    clickedConnector = nullptr;
}
void ConnectorIn::mouseMoveEvent(QMouseEvent *event)
{
    Canvas::lineRenderer->update();
}
