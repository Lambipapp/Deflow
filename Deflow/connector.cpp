#include "connector.h"
#include "ui_connector.h"
#include "canvas.h"
Connector::Connector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Connector)
{
    ui->setupUi(this);
}

Connector::~Connector()
{
    delete ui;
}

void Connector::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
//        qDebug() << "klick";
//        ui->widget->setStyleSheet(tr("background-color: Yellow"));
//        QPoint p = mapTo(Canvas::currentGraphSpace, this->geometry().center());
//        LineRenderer* lineRenderer = new LineRenderer(p, p + QPoint(100,100), Canvas::currentGraphSpace);
//        lineRenderer->show();

        Canvas::instance->currentGraphSpace->CreateLine(mapTo(Canvas::currentGraphSpace,this->parentWidget()->pos()), mapTo(Canvas::currentGraphSpace,event->pos()));
    }
}

void Connector::mouseMoveEvent(QMouseEvent* event){

}
void Connector::mouseReleaseEvent(QMouseEvent *event)
{

}
