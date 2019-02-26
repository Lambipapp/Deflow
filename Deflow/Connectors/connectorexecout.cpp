#include "connectorexecout.h"
#include "connectorexecin.h"
#include "ui_connectorexecout.h"
#include "canvas.h"

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
    next = nullptr;
    delete ui;
}
void ConnectorExecOut::mousePressEvent(QMouseEvent *event)
{
    clickedConnector = this;
}
void ConnectorExecOut::mouseReleaseEvent(QMouseEvent* event)
{
    clickedConnector = nullptr;
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
            c->BindConnection();
            BindConnection();
        }
    }
    Canvas::lineRenderer->update();
}
void ConnectorExecOut::mouseMoveEvent(QMouseEvent *event)
{
    Canvas::lineRenderer->update();
}
void ConnectorExecOut::LoseConnection()
{
    ui->Arrow->setStyleSheet(tr("background-image: url(:/new/prefix1/Arrow.png);"));
}
void ConnectorExecOut::BindConnection()
{
    ui->Arrow->setStyleSheet(tr("background-image: url(:/new/prefix1/Arrow-filled.png);"));
}
