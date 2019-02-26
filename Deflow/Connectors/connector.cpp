#include "connector.h"
#include "canvas.h"
#include <QMouseEvent>

Connector* Connector::clickedConnector = nullptr;
int Connector::cids = 0;
Connector::Connector(QWidget *parent) : QWidget(parent)
{
    id = cids++;
}
Connector::~Connector()
{

}



void Connector::mousePressEvent(QMouseEvent *event) {

}
void Connector::mouseReleaseEvent(QMouseEvent* event) {

}
void Connector::mouseMoveEvent(QMouseEvent *event) {

}

