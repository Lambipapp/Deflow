#include "graphspace.h"
#include "ui_graphspace.h"
#include "canvas.h"
#include "linerenderer.h"


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


void GraphSpace::ShowContextMenu(const QPoint &pos)
{
   QMenu contextMenu(tr("Context menu"), this);
   QMenu createBlockMenu(tr("New.."), &contextMenu);
   contextMenu.addMenu(&createBlockMenu);

   QAction createPrintBlockAction("Print block", &createBlockMenu);
   connect(&createPrintBlockAction, SIGNAL(triggered()), this, SLOT(CreatePrintBlock()));

   QAction createAddBlock("Add block", &createBlockMenu);
   connect(&createAddBlock, SIGNAL(triggered()), this, SLOT(CreateAddBlock()));

   QAction createStringBlock("string variable block", &createBlockMenu);
   connect(&createStringBlock, SIGNAL(triggered()), this, SLOT(CreateStringBlock()));

   QAction createAcquireInputBlock("Acquire Input Block", &createBlockMenu);
   connect(&createAcquireInputBlock, SIGNAL(triggered()), this, SLOT(CreateAcquireInputBlock()));

   QAction createNewVarBlock("New Variable Block", &createBlockMenu);
   connect(&createNewVarBlock, SIGNAL(triggered()), this, SLOT(CreateNewVarBlock()));

   QAction createVarBlock("Variable Block", &createBlockMenu);
   connect(&createVarBlock, SIGNAL(triggered()), this, SLOT(CreateVarBlock()));

   QAction createConditionalBlock("Conditional Block", &createBlockMenu);
   connect(&createConditionalBlock, SIGNAL(triggered()), this, SLOT(CreateConditionalBlock()));

   createBlockMenu.addAction(&createVarBlock);
   createBlockMenu.addAction(&createConditionalBlock);
   createBlockMenu.addAction(&createAddBlock);
   createBlockMenu.addAction(&createPrintBlockAction);
   createBlockMenu.addAction(&createStringBlock);
   createBlockMenu.addAction(&createAcquireInputBlock);
   createBlockMenu.addAction(&createNewVarBlock);


   newBlockPos = pos;
   contextMenu.exec(mapToGlobal(pos));
}
void GraphSpace::CreateConditionalBlock()
{
    ConditionalBlock *n = new ConditionalBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
}
void GraphSpace::CreateVarBlock()
{
    VarBlock *n = new VarBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
}
void GraphSpace::CreatePrintBlock()
{
    PrintBlock *n = new PrintBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
}

void GraphSpace::CreateNewVarBlock()
{
    NewVarBlock *n = new NewVarBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
}

void GraphSpace::CreateAcquireInputBlock()
{
    AcquireInputBlock *n = new AcquireInputBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
}

void GraphSpace::CreateAddBlock()
{
    AddBlock *n = new AddBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
}
void GraphSpace::CreateStringBlock()
{
    StringBlock *n = new StringBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
}
void GraphSpace::CreateStartBlock()
{
    StartBlock *n = new StartBlock(this);
    n->show();
    n->move(100, this->height()/2);
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

        //Update all connected lines to the selected block

    }
    Canvas::lineRenderer->update();
}

void GraphSpace::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}


void GraphSpace::dropEvent(QDropEvent *event)
{
    BaseBlock::selectedBlock = nullptr;
    event->acceptProposedAction();

}

void GraphSpace::TranslateToLua()
{

}

void GraphSpace::RemoveBlock(BaseBlock* block)
{
    for(unsigned int i = 0; i < blocks.size(); i++)
    {
        if(blocks[i] == block)
        {
            blocks.erase(blocks.begin() + i);
            break;
        }
    }
}
