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
    clickedConnector = nullptr;
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
            c->BindConnection();
            BindConnection();
        }
    }
    Canvas::lineRenderer->update();
}
void ConnectorIn::mouseMoveEvent(QMouseEvent *event)
{
    Canvas::lineRenderer->update();
}
void ConnectorIn::LoseConnection()
{
    //ui->Node->setStyleSheet(tr("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.477528 rgba(255, 255, 255, 0), stop:0.679775 rgba(0, 0, 0, 220), stop:0.691011 rgba(0, 0, 0, 225), stop:0.904494 rgba(255, 255, 255, 0));"));
    ui->Node->setStyleSheet(tr("background-image: url(:/new/prefix1/Circle.png);"));
}
void ConnectorIn::BindConnection()
{
    ui->Node->setStyleSheet(tr("background-image: url(:/new/prefix1/Circle-filled.png);"));
}

