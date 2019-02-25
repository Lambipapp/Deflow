#include "canvas.h"
#include "ui_canvas.h"


Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas)
{
    ui->setupUi(this);
    if(Canvas::instance == nullptr)
    {
        Canvas::instance = this;
    }
    else
    {
        destroy(); //dont know if this is correct
    }
    setAcceptDrops(true);
    currentGraphSpace = ui->InitCanvas;
    lineRenderer = new LineRenderer(currentGraphSpace);
}

void Canvas::CreatePrintBlock(const QPoint &pos)
{
//    PrintBlock *n = new PrintBlock(currentGraphSpace);
//    n->show();
//    n->move(pos);
//    currentGraphSpace->blocks.push_back(n);
}
void Canvas::CreateAddBlock(const QPoint &pos)
{
//    AddBlock *n = new AddBlock(currentGraphSpace);
//    n->show();
//    n->move(pos);
//    currentGraphSpace->blocks.push_back(n);
}
void Canvas::CreateStartBlock(const QPoint &pos)
{
//    StartBlock *n = new StartBlock(currentGraphSpace);
//    n->show();
//    n->move(pos);
//    currentGraphSpace->blocks.push_back(n);
}



void Canvas::RemoveBlock(BaseBlock* block)
{
    for(unsigned int i = 0; i < currentGraphSpace->blocks.size(); i++)
    {
        if(currentGraphSpace->blocks[i] == block)
        {
            currentGraphSpace->blocks.erase(currentGraphSpace->blocks.begin() + i);
            break;
        }
    }
}


void Canvas::OpenFile()
{

}



Canvas::~Canvas()
{
    delete ui;
}

GraphSpace* Canvas::currentGraphSpace;
Canvas* Canvas::instance;
LineRenderer* Canvas::lineRenderer;

void Canvas::on_FunctionTabs_currentChanged(int index)
{
    switch(index)
    {
    case 0:
        currentGraphSpace = ui->InitCanvas;
        break;
    case 1:
        currentGraphSpace = ui->UpdateCanvas;
        break;
    case 2:
        currentGraphSpace = ui->OnMessageCanvas;
        break;
    case 3:
        currentGraphSpace = ui->OnInputCanvas;
        break;
    case 4:
        currentGraphSpace = ui->OnReloadCanvas;
        break;
    case 5:
        currentGraphSpace = ui->FinalCanvas;
        break;
    }
    lineRenderer->setParent(currentGraphSpace);
    lineRenderer->show();
}
