#include "connectorout.h"
#include <QDebug>


ConnectorOut::ConnectorOut(QWidget* parent) :
    Connector(parent)
{

}

void ConnectorOut::mousePressEvent(QMouseEvent* event)
{
    qDebug() << "Hora";
//    if(event->button() == Qt::LeftButton)
//    {
//        if(selected != nullptr && selected != this) //Spawn line
//        {
//            Canvas::currentGraphSpace->CreateLine(this,selected);
//            selected = nullptr;
//        }
//        else
//        {
//            selected = this;
//        }
//    }
}

void ConnectorOut::mouseMoveEvent(QMouseEvent* event)
{
    //set currentLine ePos to mouse
}
void ConnectorOut::mouseReleaseEvent(QMouseEvent *event)
{
    //check if mouse is over another connector
}
