#include "graphspace.h"
#include "ui_graphspace.h"
#include "canvas.h"


GraphSpace::GraphSpace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphSpace)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    setContextMenuPolicy(Qt::CustomContextMenu);
}

GraphSpace::~GraphSpace()
{
    delete ui;
}

void GraphSpace::ShowContextMenu(const QPoint &pos)
{
   QMenu contextMenu(tr("Context menu"), this);
   QMenu createBlockMenu(tr("New.."), &contextMenu);
   contextMenu.addMenu(&createBlockMenu);

   QAction createPrintBlockAction("Print block", &createBlockMenu);
   connect(&createPrintBlockAction, SIGNAL(triggered()), this, SLOT(CreatePrintBlock()));

   QAction createAddBlock("Add block", &createBlockMenu);
   connect(&createAddBlock, SIGNAL(triggered()), this, SLOT(CreateAddBlock()));

   createBlockMenu.addAction(&createAddBlock);
   createBlockMenu.addAction(&createPrintBlockAction);


   newBlockPos = pos;
   contextMenu.exec(mapToGlobal(pos));
}

void GraphSpace::CreatePrintBlock()
{
    Canvas::instance->CreatePrintBlock(newBlockPos);
}

void GraphSpace::CreateAddBlock()
{
    Canvas::instance->CreateAddBlock(newBlockPos);
}

void GraphSpace::mousePressEvent(QMouseEvent* event)
{
    //start drag event
    if(event->button() == Qt::LeftButton)
    {
        previousMouseDragPos = event->pos();
        QDrag* drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData;
        mimeData->setText("CanvasDrag");
        drag->setMimeData(mimeData);
        drag->start();
    }
    else if(event->button() == Qt::RightButton)
    {
        ShowContextMenu(event->pos());
    }
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

void GraphSpace::TranslateToLua()
{

}
