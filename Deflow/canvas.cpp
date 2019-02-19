#include "canvas.h"
#include <QPainter>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QWheelEvent>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    setAcceptDrops(true);
}

Canvas::Canvas(int width, int heigth, QWidget *parent) : QWidget(parent)
{
    setMinimumSize(width,heigth);
    setAcceptDrops(true);
}


void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(event->rect(), Qt::white);
}

void Canvas::mousePressEvent(QMouseEvent* event)
{
    //start drag event
    previousMouseDragPos = event->pos();
    QDrag* drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    mimeData->setText("CanvasDrag");
    drag->setMimeData(mimeData);
    drag->start();
}

void Canvas::mouseReleaseEvent(QMouseEvent* event)
{
    //stop drag event
    TestBlock::selectedBlock = nullptr;
}

void Canvas::dragMoveEvent(QDragMoveEvent *event)
{
    if(event->mimeData()->text() == "CanvasDrag")
    {

        for(unsigned int i = 0; i < blocks.size(); i++)
        {
            blocks[i]->move(blocks[i]->pos() + (event->pos() - previousMouseDragPos));
        }
        previousMouseDragPos = event->pos();
    }
    else
    {
        TestBlock::selectedBlock->move(event->pos() - TestBlock::selectedBlock->mouseOffset);
    }
}

void Canvas::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}


void Canvas::dropEvent(QDropEvent *event)
{
    event->acceptProposedAction();
    //blocks[0]->move(event->pos());
}

