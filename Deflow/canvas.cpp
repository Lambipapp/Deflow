#include "canvas.h"
#include "ui_canvas.h"

Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas)
{
    ui->setupUi(this);
    setAcceptDrops(true);
}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::mousePressEvent(QMouseEvent* event)
{
    //start drag event
    previousMouseDragPos = event->pos();
    QDrag* drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    mimeData->setText("CanvasDrag");
    drag->setMimeData(mimeData);
    drag->start();
}

void Canvas::mouseReleaseEvent(QMouseEvent* event)
{
    //stop drag event
    BaseBlock::selectedBlock = nullptr;
}

void Canvas::dragMoveEvent(QDragMoveEvent *event)
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

void Canvas::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}


void Canvas::dropEvent(QDropEvent *event)
{
    event->acceptProposedAction();
    //blocks[0]->move(event->pos());
}
