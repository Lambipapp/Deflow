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
    gSpaces.push_back(ui->InitCanvas);
    gSpaces.push_back(ui->UpdateCanvas);
    gSpaces.push_back(ui->OnMessageCanvas);
    gSpaces.push_back(ui->OnInputCanvas);
    gSpaces.push_back(ui->OnReloadCanvas);
    gSpaces.push_back(ui->FinalCanvas);
}

void Canvas::SaveVisualCode()
{

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

QList<GraphSpace*> Canvas::GetGraphSpaces()
{
    return gSpaces;
}
