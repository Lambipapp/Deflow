#include "canvas.h"
#include "ui_canvas.h"
#include "graphspace.h"

Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas)
{
    ui->setupUi(this);
    setAcceptDrops(true);
    currentCanvas = ui->InitCanvas;
    currentGraphSpace = ui->InitCanvas;
}

Canvas::~Canvas()
{
    delete ui;
}

QWidget* Canvas::currentCanvas = nullptr;
GraphSpace* Canvas::currentGraphSpace;

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
    currentCanvas = currentGraphSpace;
}
