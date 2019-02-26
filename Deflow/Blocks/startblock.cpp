#include "startblock.h"
#include "ui_startblock.h"
#include <QMenu>

StartBlock::StartBlock(QWidget *parent) :
    BaseBlock(parent),
    ui(new Ui::StartBlock)
{
    ui->setupUi(this);
    ui->Start->setAttribute(Qt::WA_TransparentForMouseEvents);
    initConnectors();

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

QJsonObject StartBlock::GetJsonRepresentation()
{

    QJsonObject pos;
    pos.insert("x", this->pos().x());
    pos.insert("y", this->pos().y());
    QJsonObject data;
    data.insert("Position", pos);
    data.insert("Connectors", ParseConnectors());
    QJsonObject o;
    o.insert("StartBlock", data);

    return o;
}


