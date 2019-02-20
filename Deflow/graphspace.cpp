#include "graphspace.h"
#include "ui_graphspace.h"

GraphSpace::GraphSpace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphSpace)
{
    ui->setupUi(this);
    setAcceptDrops(true);
}

GraphSpace::~GraphSpace()
{
    delete ui;
}


void GraphSpace::mousePressEvent(QMouseEvent* event)
{
    //start drag event
    previousMouseDragPos = event->pos();
    QDrag* drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    mimeData->setText("CanvasDrag");
    drag->setMimeData(mimeData);
    drag->start();
}

void GraphSpace::mouseReleaseEvent(QMouseEvent* event)
{
    //stop drag event
    BaseBlock::selectedBlock = nullptr;
}

void GraphSpace::dragMoveEvent(QDragMoveEvent *event)
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
        BaseBlock::selectedBlock->move(event->pos() - BaseBlock::selectedBlock->mouseOffset);
    }
}

void GraphSpace::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}


void GraphSpace::dropEvent(QDropEvent *event)
{
    event->acceptProposedAction();
}
