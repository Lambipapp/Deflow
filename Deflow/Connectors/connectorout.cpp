#include "connectorout.h"
#include "ui_connectorout.h"
#include "connectorin.h"
#include <QDebug>
#include "canvas.h"

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

void ConnectorOut::mousePressEvent(QMouseEvent *event)
{
    clickedConnector = this;
}
void ConnectorOut::mouseReleaseEvent(QMouseEvent* event)
{
    clickedConnector = nullptr;
    QWidget* widget = qApp->widgetAt(event->globalPos());

    if(widget == this)
    {
        Canvas::lineRenderer->update();
        return;
    }
    if(widget->inherits("Connector"))
    {
        Connector* temp = static_cast<Connector*>(widget);
        if(temp->myType == NodeType::varIn)
        {
            if(temp->myBlock == myBlock){
                Canvas::lineRenderer->update();
                return;
            }
            ConnectorIn* c = static_cast<ConnectorIn*>(widget);
            c->input = this;
            c->BindConnection();
            BindConnection();
        }
    }
    Canvas::lineRenderer->update();
}
void ConnectorOut::mouseMoveEvent(QMouseEvent *event)
{
    Canvas::lineRenderer->update();
}
void ConnectorOut::LoseConnection()
{
    ui->Node->setStyleSheet(tr("background-image: url(:/new/prefix1/Circle.png);"));
}
void ConnectorOut::BindConnection()
{
    ui->Node->setStyleSheet(tr("background-image: url(:/new/prefix1/Circle-filled.png);"));
}

