#include "connector.h"
#include "ui_connector.h"

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
        qDebug() << "klick";
        ui->widget->setStyleSheet(tr("background-color: Yellow"));
        LineRenderer* lineRenderer = new LineRenderer(this->pos(), this->pos()+ QPoint(100,100));
        lineRenderer->show();
    }
}
