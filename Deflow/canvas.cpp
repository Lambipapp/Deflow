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
}

void Canvas::CreatePrintBlock(const QPoint &pos)
{
    PrintBlock *n = new PrintBlock(currentGraphSpace);
    n->show();
    n->move(pos);
    currentGraphSpace->blocks.push_back(n);
}
void Canvas::CreateAddBlock(const QPoint &pos)
{
    AddBlock *n = new AddBlock(currentGraphSpace);
    n->show();
    n->move(pos);
    currentGraphSpace->blocks.push_back(n);
}



void Canvas::RemoveBlock(BaseBlock* block)
{

}



Canvas::~Canvas()
{
    delete ui;
}

GraphSpace* Canvas::currentGraphSpace;
Canvas* Canvas::instance;

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
}
