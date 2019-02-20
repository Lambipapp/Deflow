#ifndef GRAPHSPACE_H
#define GRAPHSPACE_H

#include <QWidget>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QWheelEvent>
#include "Blocks/baseblock.h"
#include "Blocks/printblock.h"


namespace Ui {
class GraphSpace;
}

class GraphSpace : public QWidget
{
    Q_OBJECT

public:
    explicit GraphSpace(QWidget *parent = nullptr);
    ~GraphSpace();
    std::vector<BaseBlock*> blocks;

private:
    Ui::GraphSpace *ui;
    QPoint previousMouseDragPos;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
};

#endif // GRAPHSPACE_H
