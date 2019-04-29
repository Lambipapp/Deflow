#ifndef COMPAREBLOCK_H
#define COMPAREBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class CompareBlock;
}

class CompareBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit CompareBlock(QWidget *parent = nullptr);
    ~CompareBlock() override;
    QString getLuaCodeLine() override;

private:
    Ui::CompareBlock *ui;
};

#endif // COMPAREBLOCK_H
