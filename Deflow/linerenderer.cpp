#include "linerenderer.h"
#include "ui_linerenderer.h"
#include "canvas.h"

LineRenderer::LineRenderer(const QPoint &startPos, const QPoint &endPos, QWidget *parent) :
    QWidget(Canvas::currentGraphSpace),
    ui(new Ui::LineRenderer), sPos(startPos), ePos(endPos)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TransparentForMouseEvents);
    //parent = Canvas::currentGraphSpace;

}

LineRenderer::~LineRenderer()
{
    delete ui;
}


void LineRenderer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen(Qt::green, 3, Qt::SolidLine, Qt::RoundCap);
    painter.setPen(pen);

    QPainterPath smootPath;
    smootPath.moveTo(sPos);

    for(int i = sPos.x(); i < ePos.x(); i += (ePos.x() - sPos.x())/16)
    {
        float j = (float(1) - float(0))/(ePos.x() - sPos.x())*(i-sPos.x());
        float h = smoothstep(0, 1, j);
        int y =  ePos.y() - sPos.y();
        y *= h;
        y += sPos.y();

        smootPath.lineTo(QPoint(i, y));
    }
    painter.drawPath(smootPath);
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
