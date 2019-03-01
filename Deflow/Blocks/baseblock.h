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
#include "Connectors/connectorexecin.h"
#include "Connectors/connectorexecout.h"
#include <vector>
#include <QJsonObject>

class BaseBlock : public QWidget
{
    Q_OBJECT
public:
    explicit BaseBlock(QWidget *parent = nullptr);


    static BaseBlock *selectedBlock;
    QPoint mouseOffset;
    std::vector<Connector*> connectors;



    std::vector<ConnectorExecOut*> myExecOutConnectors;

    virtual QJsonObject GetJsonRepresentation();
    virtual QString getLuaCodeLine();
    virtual void ReLoadData(QJsonObject data);

    enum BlockType {
        StartBlock, VarBlock, NewVarBlock, ConditionalBlock,
        AddBlock, PrintBlock, StringBlock, AcquireInputBlock,
        GetGOPropertysBlock, SetGOPropertysBlock, SetVarBlock,
        SubtractBlock, ConstantVarBlock, MultiplicationBlock,
        DivisionBlock, InputBlock};
    BlockType myType;

signals:

public slots:
    void DestroyBlock();

private:
    QPoint dragStartPosition;
    virtual void ShowContextMenu(const QPoint &pos);
    virtual void OnDestroy();
    QDrag* drag = nullptr;
    QMimeData* mimeData = nullptr;
protected:
    QPoint posFromjsv(QJsonValue pos);
    void initConnectors();
    QJsonObject ParseConnectors();
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

};

#endif // BASEBLOCK_H
