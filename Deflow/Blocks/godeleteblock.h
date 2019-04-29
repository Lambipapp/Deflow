#ifndef GODELETEBLOCK_H
#define GODELETEBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class GoDeleteBlock;
}

class GoDeleteBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit GoDeleteBlock(QWidget *parent = nullptr);
    ~GoDeleteBlock() override;

    QString getLuaCodeLine() override;

private:
    Ui::GoDeleteBlock *ui;
};

#endif // GODELETEBLOCK_H
