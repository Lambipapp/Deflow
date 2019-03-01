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

    BaseBlock* CreateBlock(int bt);
    BaseBlock* CreateBlock(BaseBlock::BlockType bt);

private:
    Ui::GraphSpace *ui;
    QPoint previousMouseDragPos;
    QPoint newBlockPos;

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
    GetGOPropertysBlock*    CreateGetGOPropertysBlock();
    SetGOPropertysBlock*    CreateSetGOPropertysBlock();
    SetVarBlock*            CreateSetVarBlock();
    ConstantVarBlock*       CreateConstantVarBlock();
    void ShowContextMenu(const QPoint &pos);
private slots:
    void on_pushButton_clicked();
};

#endif // GRAPHSPACE_H
