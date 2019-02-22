#include "connector.h"
#include "ui_connector.h"
#include "canvas.h"

#include "linerenderer.h"

Connector *Connector::selected = nullptr;


Connector::Connector(QWidget *parent) :
QWidget(parent), ui(new Ui::Connector)
{
    ui->setupUi(this);

//    QWidget* temp = this;
//    while(temp->parentWidget() && !temp->inherits("BaseBlock"))
//    {
//        temp = temp->parentWidget();
//    }
//    qDebug() << temp->objectName();
//    myBlock = static_cast<BaseBlock*>(temp);

}


Connector::~Connector()
{
    delete ui;
}


void Connector::mousePressEvent(QMouseEvent* event)
{
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

void Connector::mouseMoveEvent(QMouseEvent* event)
{
    //set currentLine ePos to mouse
}
void Connector::mouseReleaseEvent(QMouseEvent *event)
{
    //check if mouse is over another connector
}
