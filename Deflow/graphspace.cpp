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
    startBlock = CreateStartBlock();
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

    QAction createAddBlock("Addition", &createBlockMenu);
    connect(&createAddBlock, SIGNAL(triggered()), this, SLOT(CreateAddBlock()));

    QAction createSubtractBlock("Subtraction", &createBlockMenu);
    connect(&createSubtractBlock, SIGNAL(triggered()), this, SLOT(CreateSubtractBlock()));

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

    QAction createSetGoBlock("Set GO Properties Block", &createBlockMenu);
    connect(&createSetGoBlock, SIGNAL(triggered()), this, SLOT(CreateSetGOPropertysBlock()));

    QAction createGetGoBlock("Get GO Properties Block", &createBlockMenu);
    connect(&createGetGoBlock, SIGNAL(triggered()), this, SLOT(CreateGetGOPropertysBlock()));

    QAction createSetVarBlock("Set Variable Block", &createBlockMenu);
    connect(&createSetVarBlock, SIGNAL(triggered()), this, SLOT(CreateSetVarBlock()));

    QAction createConstantVarBlock("Constant Block", &createBlockMenu);
    connect(&createConstantVarBlock, SIGNAL(triggered()),this, SLOT(CreateConstantVarBlock()));

    //createBlockMenu.addAction(&createVarBlock);
    createBlockMenu.addAction(&createConditionalBlock);
    createBlockMenu.addAction(&createPrintBlockAction);
    //createBlockMenu.addAction(&createStringBlock);
    createBlockMenu.addAction(&createAcquireInputBlock);
    //createBlockMenu.addAction(&createNewVarBlock);
    //createBlockMenu.addAction(&createSetVarBlock);


    QMenu *mathMenu = createBlockMenu.addMenu(tr("Math blocks"));
    mathMenu->addAction(&createAddBlock);
    mathMenu->addAction(&createSubtractBlock);
    //multipy block
    //divide block
    //vector length/magnitude block
    //Vector distance block

    QMenu *varMenu = createBlockMenu.addMenu(tr("variable blocks"));
    varMenu->addAction(&createNewVarBlock);
    varMenu->addAction(&createVarBlock);
    varMenu->addAction(&createStringBlock);
    varMenu->addAction(&createSetVarBlock);
    varMenu->addAction(&createConstantVarBlock);

    QMenu *goBlockMenu = createBlockMenu.addMenu(tr("Game Object blocks"));
    goBlockMenu->addAction(&createGetGoBlock);
    goBlockMenu->addAction(&createSetGoBlock);


    newBlockPos = pos;
    contextMenu.exec(mapToGlobal(pos));
}
ConditionalBlock* GraphSpace::CreateConditionalBlock()
{
    ConditionalBlock *n = new ConditionalBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
    return n;
}
VarBlock* GraphSpace::CreateVarBlock()
{
    VarBlock *n = new VarBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
    return n;
}
SetVarBlock* GraphSpace::CreateSetVarBlock()
{
    SetVarBlock *n = new SetVarBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
    return n;
}
ConstantVarBlock* GraphSpace::CreateConstantVarBlock()
{
    ConstantVarBlock *n = new ConstantVarBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
    return n;
}
PrintBlock* GraphSpace::CreatePrintBlock()
{
    PrintBlock *n = new PrintBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
    return n;
}

NewVarBlock* GraphSpace::CreateNewVarBlock()
{
    NewVarBlock *n = new NewVarBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
    return n;
}

AcquireInputBlock* GraphSpace::CreateAcquireInputBlock()
{
    AcquireInputBlock *n = new AcquireInputBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
    return n;
}

AddBlock* GraphSpace::CreateAddBlock()
{
    AddBlock *n = new AddBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
    return n;
}
SubtractBlock* GraphSpace::CreateSubtractBlock()
{
    SubtractBlock *n = new SubtractBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
    return n;
}
StringBlock* GraphSpace::CreateStringBlock()
{
    StringBlock *n = new StringBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
    return n;

}
StartBlock* GraphSpace::CreateStartBlock()
{
    StartBlock *n = new StartBlock(this);
    n->show();
    n->move(100, this->height()/2);
    this->blocks.push_back(n);
    return n;
}
GetGOPropertysBlock* GraphSpace::CreateGetGOPropertysBlock()
{
    GetGOPropertysBlock *n = new GetGOPropertysBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
    return n;
}

SetGOPropertysBlock* GraphSpace::CreateSetGOPropertysBlock()
{
    SetGOPropertysBlock *n = new SetGOPropertysBlock(this);
    n->show();
    n->move(newBlockPos);
    this->blocks.push_back(n);
    return n;
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
BaseBlock* GraphSpace::CreateBlock(int bt)
{
    switch (bt) {
    case BaseBlock::BlockType::StartBlock:
        return CreateStartBlock();
    case BaseBlock::BlockType::AddBlock:
        return CreateAddBlock();
    case BaseBlock::BlockType::VarBlock:
        return CreateVarBlock();
    case BaseBlock::BlockType::PrintBlock:
        return CreatePrintBlock();
    case BaseBlock::BlockType::NewVarBlock:
        return CreateNewVarBlock();
    case BaseBlock::BlockType::StringBlock:
        return CreateStringBlock();
    case BaseBlock::BlockType::ConditionalBlock:
        return CreateConditionalBlock();
    case BaseBlock::BlockType::AcquireInputBlock:
        return CreateAcquireInputBlock();
    case BaseBlock::BlockType::GetGOPropertysBlock:
        return CreateGetGOPropertysBlock();
    case BaseBlock::BlockType::SetGOPropertysBlock:
        return CreateSetGOPropertysBlock();
    case BaseBlock::BlockType::SubtractBlock:
        return CreateSubtractBlock();
    case BaseBlock::BlockType::ConstantVarBlock:
        return CreateConstantVarBlock();
    }

    return nullptr;
}

BaseBlock* GraphSpace::CreateBlock(BaseBlock::BlockType bt)
{
    return CreateBlock(static_cast<int>(bt));
}


//TEMP //TEMP//TEMP//TEMP//TEMP//TEMP//TEMP//TEMP//TEMP//TEMP//TEMP//TEMP//TEMP//TEMP//TEMP//TEMP//TEMP//TEMP//TEMP//TEMP//TEMP//TEMP//TEMP//TEMP
#include "filemanager.h"
void GraphSpace::on_pushButton_clicked()
{
    FileManager::fm->TranslateAndWriteToCurrentFile();
}
