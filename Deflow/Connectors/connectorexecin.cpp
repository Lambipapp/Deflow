#include "connectorexecin.h"
#include "connectorexecout.h"
#include "ui_connectorexecin.h"
#include "canvas.h"


ConnectorExecIn::ConnectorExecIn(QWidget *parent) :
    Connector(parent),
    ui(new Ui::ConnectorExecIn)
{
    ui->setupUi(this);
    ui->Arrow->setAttribute(Qt::WA_TransparentForMouseEvents);
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
        if(temp->myType == NodeType::execOut)
        {
            if(temp->myBlock == myBlock){
                Canvas::lineRenderer->update();
                return;
            }
            ConnectorExecOut* c = static_cast<ConnectorExecOut*>(widget);
            c->next = this;
            c->BindConnection();
            BindConnection();
        }
    }
    Canvas::lineRenderer->update();
}
void ConnectorExecIn::mouseMoveEvent(QMouseEvent *event)
{
    Canvas::lineRenderer->update();
}

void ConnectorExecIn::LoseConnection()
{
    ui->Arrow->setStyleSheet(tr("background-image: url(:/new/prefix1/Arrow.png);"));
}
void ConnectorExecIn::BindConnection()
{
    ui->Arrow->setStyleSheet(tr("background-image: url(:/new/prefix1/Arrow-filled.png);"));
}

