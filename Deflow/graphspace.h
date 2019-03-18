#ifndef GRAPHSPACE_H
#define GRAPHSPACE_H

#include <QWidget>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QMenu>
#include "blocks.h"
#include <QDebug>
#include <QPainter>


namespace Ui {
class GraphSpace;
}

class GraphSpace : public QWidget
{
    Q_OBJECT

public:
    explicit GraphSpace(QWidget *parent = nullptr);
    ~GraphSpace() override;
    std::vector<BaseBlock*> blocks;
    StartBlock* startBlock;

    //BaseBlock* CreateBlock(int bt);
    //BaseBlock* CreateBlock(BaseBlock::BlockType bt);

private:
    Ui::GraphSpace *ui;
    QPoint previousMouseDragPos;
    QPoint newBlockPos;
    QDrag* drag;
    QMimeData* mimeData;

    void TranslateToLua();




protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;

public slots:
    void RemoveBlock(BaseBlock* block);
    PrintBlock*             CreatePrintBlock();
    StringBlock*            CreateStringBlock();
    AddBlock*               CreateAddBlock();
    SubtractBlock*          CreateSubtractBlock();
    StartBlock*             CreateStartBlock();
    AcquireInputBlock*      CreateAcquireInputBlock();
    NewVarBlock*            CreateNewVarBlock();
    VarBlock*               CreateVarBlock();
    ConditionalBlock*       CreateConditionalBlock();
    GetPositionBlock*       CreateGetPositionBlock();
    GetRotationBlock*       CreateGetRotationBlock();
    GetScaleBlock*          CreateGetScaleBlock();
    SetGOPropertysBlock*    CreateSetGOPropertysBlock();
    SetVarBlock*            CreateSetVarBlock();
    ConstantVarBlock*       CreateConstantVarBlock();
    VectorConstantBlock*    CreateConstantVectorBlock();
    MultiplicationBlock*    CreateMultiplicationBlock();
    DivisionBlock*          CreateDivisionBlock();
    InputBlock*             CreateInputBlock();
    LoopBlock*              CreateLoopBlock();
    void ShowContextMenu(const QPoint &pos);
};

#endif // GRAPHSPACE_H
