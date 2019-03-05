#ifndef LOOPBLOCK_H
#define LOOPBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class LoopBlock;
}

class LoopBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit LoopBlock(QWidget *parent = nullptr);
    ~LoopBlock() override;
    QString getLuaCodeLine() override;

private:
    Ui::LoopBlock *ui;
};

#endif // LOOPBLOCK_H
