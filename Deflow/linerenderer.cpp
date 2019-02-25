#include "linerenderer.h"
#include "ui_linerenderer.h"
#include "canvas.h"
#include <QDebug>
#include "connectorexecout.h"
#include "connectorin.h"


LineRenderer::LineRenderer(QWidget *parent) :
    QWidget(parent), ui(new Ui::LineRenderer)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TransparentForMouseEvents);


}

LineRenderer::~LineRenderer()
{
    delete ui;
}


void LineRenderer::paintEvent(QPaintEvent *event)
{
    raise();
    move(parentWidget()->pos());
    resize(parentWidget()->size());
    FindConnections();

}

float LineRenderer::map(float newMin, float newMax, float oldMin, float oldMax, float val){
    return (newMax - newMin)/(oldMax - oldMin)*(val-oldMin);
}
float LineRenderer::smoothstep(float edge0, float edge1, float x) {
  x = clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0);
  return x * x * (3 - 2 * x);
}

float LineRenderer::clamp(float x, float lowerlimit, float upperlimit) {
  if (x < lowerlimit)
    x = lowerlimit;
  if (x > upperlimit)
    x = upperlimit;
  return x;
}
void LineRenderer::FindConnections(){

    for(Connector *c : parentWidget()->findChildren<Connector*>())
    {
        if(c->myType == Connector::NodeType::execOut)
        {
            ConnectorExecOut* t = static_cast<ConnectorExecOut*>(c);
            if(t->next != nullptr)
            {
                DrawLine(t->parentWidget()->mapTo(Canvas::currentGraphSpace, t->geometry().center()),
                         t->next->parentWidget()->mapTo(Canvas::currentGraphSpace, t->next->geometry().center()), Qt::gray);
            }
        }
        else if(c->myType == Connector::NodeType::varIn)
        {
            ConnectorIn* t = static_cast<ConnectorIn*>(c);
            if(t->input != nullptr)
            {
                DrawLine(t->parentWidget()->mapTo(Canvas::currentGraphSpace, t->geometry().center()),
                         t->input->parentWidget()->mapTo(Canvas::currentGraphSpace, t->input->geometry().center()), Qt::green);
            }
        }
        if(c == Connector::clickedConnector)
        {
            DrawLine(c->parentWidget()->mapTo(Canvas::currentGraphSpace, c->geometry().center()),
                     mapFromGlobal(QCursor::pos()), Qt::blue);
        }
    }
}
void LineRenderer::DrawLine(QPoint a, QPoint b, QColor c)
{

    QPainter painter(this);
    QPen pen(c, lineWidth, Qt::SolidLine, Qt::RoundCap);
    painter.setPen(pen);

    if(a.x() > b.x()) {
        QPoint x = a;
        a = b;
        b = x;
    }

    QPainterPath smoothPath(a);
    int resoultion = 8;
    int dx = b.x()-a.x();
    int dy = b.y()-a.y();

    for(int i = 0; i < resoultion; i++)
    {
        int xPos =  (dx / resoultion)*i;
        float yVal = map(0, 1, 0, dx, xPos);
        xPos += a.x();
        float yPosf = smoothstep(0,1,yVal);
        int yPos = a.y() + static_cast<int>(yPosf * dy);
        smoothPath.lineTo(xPos, yPos);
    }

    smoothPath.lineTo(b);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawPath(smoothPath);


}



