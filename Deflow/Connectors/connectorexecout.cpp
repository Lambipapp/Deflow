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
    LoseConnection(this);
    next = nullptr;
    delete ui;
}
void ConnectorExecOut::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        clickedConnector = this;
    else if(event->button() == Qt::RightButton)
    {
        if(next != nullptr)
        {
            LoseConnection(this);
        }
    }
}
void ConnectorExecOut::mouseReleaseEvent(QMouseEvent* event)
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
        if(temp->myType == NodeType::execIn)
        {
            if(temp->myBlock == myBlock){
                Canvas::lineRenderer->update();
                return;
            }
            ConnectorExecIn* c = static_cast<ConnectorExecIn*>(widget);
            if(next != nullptr) next->LoseConnection(this);
            next = c;
            c->BindConnection(this);
            BindConnection(c);
        }
    }
    Canvas::lineRenderer->update();
}
void ConnectorExecOut::mouseMoveEvent(QMouseEvent *event)
{
    Canvas::lineRenderer->update();
}
void ConnectorExecOut::LoseConnection(Connector* c)
{
    if(c == this)
    {
        if(next != nullptr)
            next->LoseConnection(this);
    }
    next = nullptr;
    ui->Arrow->setStyleSheet(tr("background-image: url(:/new/prefix1/Arrow.png);"));
}
void ConnectorExecOut::BindConnection(Connector* c)
{
    if(next != nullptr && c != next) next->LoseConnection(this);
    next = static_cast<ConnectorExecIn*>(c);
    ui->Arrow->setStyleSheet(tr("background-image: url(:/new/prefix1/Arrow-filled.png);"));
}
QJsonObject ConnectorExecOut::GetJsonRepresentation()
{
    QJsonObject o;

    o.insert("myType", myType);
    o.insert("myID", id);
    o.insert("connectedID", next != nullptr ? next->id : -1);

    return o;
}
