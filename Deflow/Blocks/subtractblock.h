#ifndef SUBTRACTBLOCK_H
#define SUBTRACTBLOCK_H

#include <QWidget>
#include "baseblock.h"
namespace Ui {
class SubtractBlock;
}

class SubtractBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit SubtractBlock(QWidget *parent = nullptr);
    ~SubtractBlock() override;

    QString getLuaCodeLine() override;

private:
    Ui::SubtractBlock *ui;
};

#endif // SUBTRACTBLOCK_H
