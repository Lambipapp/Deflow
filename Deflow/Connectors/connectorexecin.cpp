#include "connectorexecin.h"
#include "connectorexecout.h"
#include "ui_connectorexecin.h"
#include "canvas.h"


ConnectorExecIn::ConnectorExecIn(QWidget *parent) :
    Connector(parent),
    ui(new Ui::ConnectorExecIn)
{
    ui->setupUi(this);
    ui->widget->setAttribute(Qt::WA_TransparentForMouseEvents);
    myType = NodeType::execIn;
}

ConnectorExecIn::~ConnectorExecIn()
{

    delete ui;
}

void ConnectorExecIn::mousePressEvent(QMouseEvent *event)
{
    clickedConnector = this;
}
void ConnectorExecIn::mouseReleaseEvent(QMouseEvent* event)
{
    QWidget* widget = qApp->widgetAt(event->globalPos());

    if(widget == this)
        return;

    if(widget->inherits("Connector"))
    {
        Connector* temp = static_cast<Connector*>(widget);
        if(temp->myType == NodeType::execOut)
        {
            if(temp->myBlock == myBlock)
                return;

            ConnectorExecOut* c = static_cast<ConnectorExecOut*>(widget);
            c->next = this;
        }
    }
    Canvas::lineRenderer->update();
    clickedConnector = nullptr;
}
void ConnectorExecIn::mouseMoveEvent(QMouseEvent *event)
{
    Canvas::lineRenderer->update();
}
