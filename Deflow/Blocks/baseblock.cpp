#include "baseblock.h"
#include "canvas.h"


BaseBlock* BaseBlock::selectedBlock = nullptr;


BaseBlock::BaseBlock(QWidget *parent) : QWidget(parent)
{
    setContextMenuPolicy(Qt::CustomContextMenu);
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
        ShowContextMenu(event->pos());
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

void BaseBlock::ShowContextMenu(const QPoint &pos)
{
    QMenu contextMenu(tr("Context menu"), this);

    QAction deleteBlock("Delete", &contextMenu);
    connect(&deleteBlock, SIGNAL(triggered()), this, SLOT(DestroyBlock()));
    contextMenu.addAction(&deleteBlock);

    contextMenu.setStyleSheet("");

    contextMenu.exec(mapToGlobal(pos));
}


void BaseBlock::DestroyBlock()
{
    OnDestroy();
    Canvas::instance->RemoveBlock(this);
    deleteLater();
}

void BaseBlock::OnDestroy()
{
}
