#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QWheelEvent>
#include "baseblock.h"

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget* parent = nullptr);
    std::vector<BaseBlock*> blocks;

    //create block
    template<class T>
        void CreateBlock()
        {
            T *n = new T(this);
            blocks.push_back(n);
        }

    ~Canvas();

private:
    Ui::Canvas *ui;
    QPoint previousMouseDragPos;


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;

};

#endif // CANVAS_H
