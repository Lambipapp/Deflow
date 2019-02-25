#ifndef LINERENDERER_H
#define LINERENDERER_H

#include <QWidget>
//#include "blocks.h"


namespace Ui {
class LineRenderer;
}

class LineRenderer : public QWidget
{
    Q_OBJECT

public:
    explicit LineRenderer(QWidget *parent = nullptr);
    ~LineRenderer() override;

private:
    Ui::LineRenderer *ui;
    static float map(float newMin, float newMax, float oldMin, float oldMax, float val);
    static float smoothstep(float edge0, float edge1, float x);
    static float clamp(float x, float lowerlimit, float upperlimit);
    int lineWidth = 3;

    void DrawLine( QPoint a,  QPoint b, QColor c);
    void FindConnections();
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // LINERENDERER_H
