#ifndef BASEBLOCK_H
#define BASEBLOCK_H

#include <QWidget>
#include <QMouseEvent>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QPainter>
#include <QApplication>


class BaseBlock : public QWidget
{
    Q_OBJECT
public:
    explicit BaseBlock(QWidget *parent = nullptr);

    virtual QString getLuaCodeLine() = 0;

    static BaseBlock *selectedBlock;
    QPoint mouseOffset;
signals:

public slots:


private:
    QPoint dragStartPosition;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // BASEBLOCK_H
