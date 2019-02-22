#include "linerenderer.h"
#include "ui_linerenderer.h"
#include "canvas.h"
#include <QDebug>

LineRenderer* LineRenderer::selectedLine = nullptr;


LineRenderer::LineRenderer(QWidget* p1, QWidget* p2, QWidget *parent) :
    QWidget(parent), w1(p1), w2(p2), ui(new Ui::LineRenderer)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TransparentForMouseEvents);

    sPos = w1->parentWidget()->mapTo(Canvas::currentGraphSpace, w1->geometry().center());
    ePos = w2->parentWidget()->mapTo(Canvas::currentGraphSpace, w2->geometry().center());

    padding = QPoint(halfWidth, halfWidth);
    UpdatePositions();


}

LineRenderer::~LineRenderer()
{
    delete ui;
}

void LineRenderer::UpdatePositions()
{
    sPos = w1->parentWidget()->mapTo(Canvas::currentGraphSpace, w1->geometry().center());
    ePos = w2->parentWidget()->mapTo(Canvas::currentGraphSpace, w2->geometry().center());

    if(sPos.x() < ePos.x() && sPos.y() < ePos.y()) downHill = true;
    else if(sPos.x() < ePos.x() && sPos.y() > ePos.y()) downHill = false;
    else if(sPos.x() > ePos.x() && sPos.y() < ePos.y()) downHill = false;
    else if(sPos.x() > ePos.x() && sPos.y() > ePos.y()) downHill = true;


    if(ePos.x() < sPos.x()){
        int tmp = ePos.x();
        ePos.setX(sPos.x());
        sPos.setX(tmp);
    }
    if(ePos.y() < sPos.y()){
        int tmp = ePos.y();
        ePos.setY(sPos.y());
        sPos.setY(tmp);
    }


    this->resize((ePos.x() - sPos.x())+lineWidth, (ePos.y() - sPos.y())+lineWidth);
    this->move(sPos - padding);


}

void LineRenderer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen(Qt::green, lineWidth, Qt::SolidLine, Qt::RoundCap);
    painter.setPen(pen);
    QPoint s = mapFromParent(sPos);
    QPoint e = mapFromParent(ePos);
    int width = (e.x() - s.x());
    int height = (e.y() - s.y());

    QPainterPath* smoothPath;

    if(downHill)
        smoothPath = new QPainterPath(s);
    else
        smoothPath = new QPainterPath(QPoint(s.x(), height-s.y()));

    for(int i = 0; i < 8; i ++)
    {
        int xPos = (width / 8) * i+1;
        float yVal = map(0, 1, 0, width, xPos);
        yVal = smoothstep(0, 1, yVal);
        yVal = downHill ? yVal : 1-yVal;
        int yPos = static_cast<int>((static_cast<float>(height)*yVal));

        smoothPath->lineTo(xPos, yPos);
    }

    smoothPath->lineTo(downHill ? e : QPoint(e.x(), height-e.y() + lineWidth));
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawPath(*smoothPath);
    delete smoothPath;
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
