#include "connectorin.h"
#include "ui_connectorin.h"
#include "canvas.h"
#include "baseblock.h"

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
    LoseConnection(this);
    input = nullptr;
    delete ui;
}

void ConnectorIn::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        clickedConnector = this;
    }
    else if(event->button() == Qt::RightButton){
        LoseConnection(this);
    }
}
void ConnectorIn::mouseReleaseEvent(QMouseEvent* event)
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
        if(temp->myType == NodeType::varOut)
        {
            if(temp->myBlock == myBlock){
                Canvas::lineRenderer->update();
                return;
            }
            ConnectorOut* c = static_cast<ConnectorOut*>(widget);
            if(input != nullptr) input->LoseConnection(this);
            input = c;
            c->BindConnection(this);
            BindConnection(c);
        }
    }
    Canvas::lineRenderer->update();
}
void ConnectorIn::mouseMoveEvent(QMouseEvent *event)
{
    Canvas::lineRenderer->update();
}
void ConnectorIn::LoseConnection(Connector* c)
{
    if(c == this)
    {
        if(input != nullptr)
            input->LoseConnection(this);
    }
    input = nullptr;
    ui->Node->setStyleSheet(tr("background-image: url(:/new/prefix1/Circle.png);"));
}
void ConnectorIn::BindConnection(Connector* c)
{
    if(input != nullptr && c != input) input->LoseConnection(this);
    input = static_cast<ConnectorOut*>(c);
    ui->Node->setStyleSheet(tr("background-image: url(:/new/prefix1/Circle-filled.png);"));
}
QJsonObject ConnectorIn::GetJsonRepresentation()
{
    QJsonObject o;

    return o;
}
