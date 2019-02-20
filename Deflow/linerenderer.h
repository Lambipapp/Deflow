#ifndef LINERENDERER_H
#define LINERENDERER_H

#include <QWidget>
#include <graphspace.h>
#include "blocks.h"


namespace Ui {
class LineRenderer;
}

class LineRenderer : public QWidget
{
    Q_OBJECT

public:
    explicit LineRenderer(const QPoint &startPos, const QPoint &endPos, QWidget *parent = nullptr);
    ~LineRenderer();

private:
    Ui::LineRenderer *ui;
    static float smoothstep(float edge0, float edge1, float x);
    static float clamp(float x, float lowerlimit, float upperlimit);
    QPoint sPos;
    QPoint ePos;

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // LINERENDERER_H
