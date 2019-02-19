#include "testblock.h"
#include "ui_testblock.h"
#include <QMouseEvent>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QPainter>

TestBlock::TestBlock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestBlock)
{
    ui->setupUi(this);
}

TestBlock::~TestBlock()
{
    delete ui;
}

TestBlock* TestBlock::selectedBlock = nullptr;

void TestBlock::mousePressEvent(QMouseEvent *event)
{
    dragStartPosition = event->pos();
    selectedBlock = this;
    mouseOffset = event->pos(); - this->pos();
}


void TestBlock::mouseReleaseEvent(QMouseEvent* event)
{
    selectedBlock = nullptr;
}

void TestBlock::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->pos() - dragStartPosition).manhattanLength() < QApplication::startDragDistance())
        return;

    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    drag->setMimeData(mimeData);

    drag->exec(Qt::MoveAction);
}
