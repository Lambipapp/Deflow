#include "baseblock.h"
#include "canvas.h"
#include <qdebug.h>

BaseBlock* BaseBlock::selectedBlock = nullptr;


BaseBlock::BaseBlock(QWidget *parent) : QWidget(parent)
{
    setContextMenuPolicy(Qt::CustomContextMenu);

}

void BaseBlock::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        dragStartPosition = event->pos();
        selectedBlock = this;
        mouseOffset = event->pos(); - this->pos();
    }
    else if(event->button() == Qt::RightButton)
    {
        ShowContextMenu(event->pos());
    }

}




void BaseBlock::mouseReleaseEvent(QMouseEvent* event)
{
    selectedBlock = nullptr;
}

void BaseBlock::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->pos() - dragStartPosition).manhattanLength() < QApplication::startDragDistance())
        return;

    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    drag->setMimeData(mimeData);

    drag->exec(Qt::MoveAction);
}

void BaseBlock::ShowContextMenu(const QPoint &pos)
{
    QMenu contextMenu(tr("Context menu"), this);

    QAction deleteBlock("Delete", &contextMenu);
    connect(&deleteBlock, SIGNAL(triggered()), this, SLOT(DestroyBlock()));
    contextMenu.addAction(&deleteBlock);

    contextMenu.setStyleSheet("");

    contextMenu.exec(mapToGlobal(pos));
}


void BaseBlock::DestroyBlock()
{

    OnDestroy();
    Canvas::currentGraphSpace->RemoveBlock(this);
    deleteLater();
}

void BaseBlock::OnDestroy()
{
    for(unsigned int i = 0; i < connectors.size(); i++)
        connectors[i]->LoseConnection(connectors[i]);
    Canvas::lineRenderer->update();
}

void BaseBlock::initConnectors()
{

    for(Connector* c : findChildren<Connector*>())
    {
        c->myBlock = this;
        connectors.push_back(c);
        if(c->myType == c->NodeType::execOut)
            myExecOutConnectors.push_back(static_cast<ConnectorExecOut*>(c));
    }
}
QJsonObject BaseBlock::ParseConnectors()
{
    QJsonObject o;
    for(int i = 0; i < findChildren<Connector*>().size(); i++)//Connector* c : findChildren<Connector*>())
    {
        o.insert("connector_"+ QString::number(i), findChildren<Connector*>()[i]->GetJsonRepresentation());
    }
    return o;
}
void BaseBlock::ReLoadData(QJsonObject data)
{}

QJsonObject BaseBlock::GetJsonRepresentation()
{
    return QJsonObject();
}
QString BaseBlock::getLuaCodeLine()
{
    return QString();
}
QPoint BaseBlock::posFromjsv(QJsonValue pos)
{
    return QPoint(pos.toObject().value(tr("x")).toInt(), pos.toObject().value(tr("y")).toInt());
}

