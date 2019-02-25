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
                DrawLine(t->mapFrom(Canvas::currentGraphSpace, t->pos()), t->next->mapFrom(Canvas::currentGraphSpace, t->next->pos()), Qt::red);
            }
        }
        else if(c->myType == Connector::NodeType::varIn)
        {
            ConnectorIn* t = static_cast<ConnectorIn*>(c);
            if(t->input != nullptr)
            {
                DrawLine(t->pos(), t->input->pos(), Qt::green);
            }
        }
    }
}
void LineRenderer::DrawLine(QPoint a, QPoint b, QColor c)
{

    QPainter painter(this);
    QPen pen(c, 2, Qt::SolidLine, Qt::RoundCap);
    painter.setPen(pen);

    QPainterPath* smoothPath;

    painter.drawLine(a*-1, b*-1);
    qDebug() << a << b;
//    if(a.x() > b.x()) {
//        QPoint x = a;
//        a = b;
//        b = x;
//    }
//    qDebug() << a*-1 << b*-1;
//    smoothPath = new QPainterPath(a);
//    for(int i = 0; i < 8; i ++)
//    {
//        int xPos = ((b.x()-a.x()) / 8) * i+1;
//        xPos += a.x();
//        smoothPath->lineTo(xPos, a.y());
//    }
//    //
//    //        float yVal = map(0, 1, 0, width, xPos);
//    //        yVal = smoothstep(0, 1, yVal);
//    //        yVal = downHill ? yVal : 1-yVal;
//    //        int yPos = static_cast<int>((static_cast<float>(height)*yVal));

//    //        smoothPath->lineTo(xPos, yPos);
//    //    }

//        smoothPath->lineTo(b);
//        painter.setRenderHint(QPainter::Antialiasing);
//        painter.drawPath(*smoothPath);
//        delete smoothPath;



}




