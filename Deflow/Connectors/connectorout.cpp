#include "connectorout.h"
#include "ui_connectorout.h"
#include "connectorin.h"
#include <QDebug>
#include "canvas.h"
#include "baseblock.h"

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
    LoseConnection(this);
    delete ui;
}

void ConnectorOut::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        clickedConnector = this;
    }
    else if(event->button() == Qt::RightButton){
        LoseConnection(this);
    }
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
            c->BindConnection(this);
            BindConnection(c);
        }
    }
    Canvas::lineRenderer->update();
}
void ConnectorOut::mouseMoveEvent(QMouseEvent *event)
{
    Canvas::lineRenderer->update();
}
void ConnectorOut::LoseConnection(Connector* c)
{
    if(c == this)
    {
        for(unsigned int i = 0; i < connected.size(); i++)
        {
            connected[i]->LoseConnection(this);
        }
        connected.clear();
    }
    else
    {
        for(unsigned int i = 0; i < connected.size(); i++)
        {
            if(c == connected[i])
            {

                connected.erase(connected.begin()+i);
            }
        }
    }
    ui->Node->setStyleSheet(tr("background-image: url(:/new/prefix1/Circle.png);"));



}
void ConnectorOut::BindConnection(Connector* c)
{
    if(!(std::find(connected.begin(), connected.end(), c) != connected.end())) {
        connected.push_back(c);
    }
    ui->Node->setStyleSheet(tr("background-image: url(:/new/prefix1/Circle-filled.png);"));
}
QJsonObject ConnectorOut::GetJsonRepresentation()
{
    QJsonObject o;


    return o;
}
