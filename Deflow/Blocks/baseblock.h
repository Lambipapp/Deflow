#ifndef BASEBLOCK_H
#define BASEBLOCK_H

#include <QWidget>
#include <QMouseEvent>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QPainter>
#include <QApplication>
#include <QList>

#include "Connectors/connectorin.h"
#include "Connectors/connectorout.h"
#include <vector>
#include <QJsonObject>

class BaseBlock : public QWidget
{
    Q_OBJECT
public:
    explicit BaseBlock(QWidget *parent = nullptr);

    virtual QString getLuaCodeLine() = 0;

    static BaseBlock *selectedBlock;
    QPoint mouseOffset;
    std::vector<ConnectorIn*> connectorsIN;
    std::vector<ConnectorOut*> connectorsOUT;




signals:

public slots:
    void DestroyBlock();

private:
    QPoint dragStartPosition;
    virtual void ShowContextMenu(const QPoint &pos);
    virtual void OnDestroy();


protected:
    void initConnectors();
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

};

#endif // BASEBLOCK_H
