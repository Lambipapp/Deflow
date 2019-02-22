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
    CreateStartBlock();
}

GraphSpace::~GraphSpace()
{
    delete ui;
}


void GraphSpace::CreateLine(QWidget* connector1, QWidget* connector2)
{
    LineRenderer* newLine = new LineRenderer(connector1,connector2,Canvas::currentGraphSpace);
    lines.push_back(newLine);
    newLine->show();
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
    //Canvas::instance->CreatePrintBlock(newBlockPos);
    PrintBlock *n = new PrintBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
}

void GraphSpace::CreateAddBlock()
{
    //Canvas::instance->CreateAddBlock(newBlockPos);
    AddBlock *n = new AddBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
}
void GraphSpace::CreateStartBlock()
{
    //Canvas::instance->CreateStartBlock();
    StartBlock *n = new StartBlock(this);
    n->show();
    n->move(this->width()/2, this->height()/2);
    this->blocks.push_back(n);
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


void GraphSpace::UpdateAllLines()
{
    for(unsigned int i = 0; i < lines.size(); i++){
        lines[i]->UpdatePositions();
    }
}

void GraphSpace::dragMoveEvent(QDragMoveEvent *event)
{
    if(event->mimeData()->text() == "CanvasDrag")
    {
        for(unsigned int i = 0; i < blocks.size(); i++)
        {
            blocks[i]->move(blocks[i]->pos() + (event->pos() - previousMouseDragPos));
        }
            UpdateAllLines();
        previousMouseDragPos = event->pos();
    }
    else
    {
        BaseBlock::selectedBlock->move(event->pos() - BaseBlock::selectedBlock->mouseOffset);
        UpdateAllLines();
        //Update all connected lines to the selected block
    }
}

void GraphSpace::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}


void GraphSpace::dropEvent(QDropEvent *event)
{
    UpdateAllLines();
    BaseBlock::selectedBlock = nullptr;
    event->acceptProposedAction();
}

void GraphSpace::TranslateToLua()
{

}
