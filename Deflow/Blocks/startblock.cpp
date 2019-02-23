#include "startblock.h"
#include "ui_startblock.h"
#include <QMenu>

StartBlock::StartBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::StartBlock)
{
    ui->setupUi(this);
    ui->Start->setAttribute(Qt::WA_TransparentForMouseEvents);
    //connectorsOUT.push_back(ui->Node_3);

}


StartBlock::~StartBlock()
{
    delete ui;
}

QString StartBlock::getLuaCodeLine()
{
return QString();
}

void StartBlock::ShowContextMenu(const QPoint &pos)
{
    QMenu contextMenu(tr("Context menu"), this);

    QAction deleteBlock("Test", &contextMenu);
    contextMenu.addAction(&deleteBlock);

    contextMenu.setStyleSheet("");

    contextMenu.exec(mapToGlobal(pos));
}
