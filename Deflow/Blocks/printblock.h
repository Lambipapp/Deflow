#ifndef PRINTBLOCK_H
#define PRINTBLOCK_H

#include "Blocks/baseblock.h"
#include <QWidget>

namespace Ui {
class PrintBlock;
}

class PrintBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit PrintBlock(QWidget *parent = nullptr);
    ~PrintBlock();

    QString getLuaCodeLine() override;

private:
    Ui::PrintBlock *ui;
};

#endif // PRINTBLOCK_H
