#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include "testblock.h"

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
    explicit Canvas(int width, int heigth, QWidget*parent = nullptr);
    std::vector<TestBlock*> blocks;

signals:

public slots:


private:
    QPoint previousMouseDragPos;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
};

#endif // CANVAS_H
