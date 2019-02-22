#ifndef GRAPHSPACE_H
#define GRAPHSPACE_H

#include <QWidget>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QMenu>
#include "blocks.h"
#include "linerenderer.h"
#include <QDebug>


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
    std::vector<LineRenderer*> lines;

private:
    Ui::GraphSpace *ui;
    QPoint previousMouseDragPos;
    QPoint newBlockPos;
    void TranslateToLua();
    void UpdateAllLines();



protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;

public slots:
    void CreatePrintBlock();
    void CreateAddBlock();
    void CreateStartBlock();
    void ShowContextMenu(const QPoint &pos);
    void CreateLine(QWidget* connector1, QWidget* connector2);
};

#endif // GRAPHSPACE_H
