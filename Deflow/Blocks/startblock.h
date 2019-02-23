#ifndef STARTBLOCK_H
#define STARTBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class StartBlock;
}

class StartBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit StartBlock(QWidget *parent = nullptr);
    ~StartBlock();
    QString getLuaCodeLine() override;
    virtual void ShowContextMenu(const QPoint &pos) override;

private:
    Ui::StartBlock *ui;

};

#endif // STARTBLOCK_H
