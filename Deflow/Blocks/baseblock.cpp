#include "baseblock.h"

BaseBlock* BaseBlock::selectedBlock = nullptr;


BaseBlock::BaseBlock(QWidget *parent) : QWidget(parent)
{

}

void BaseBlock::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        dragStartPosition = event->pos();
        selectedBlock = this;
        mouseOffset = event->pos(); - this->pos();
    }
    else if(event->button() == Qt::RightButton)
    {

    }

}


void BaseBlock::mouseReleaseEvent(QMouseEvent* event)
{
    selectedBlock = nullptr;
}

void BaseBlock::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->pos() - dragStartPosition).manhattanLength() < QApplication::startDragDistance())
        return;

    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    drag->setMimeData(mimeData);

    drag->exec(Qt::MoveAction);
}
