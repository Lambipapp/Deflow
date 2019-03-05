#ifndef MULTIPLICATIONBLOCK_H
#define MULTIPLICATIONBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class MultiplicationBlock;
}

class MultiplicationBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit MultiplicationBlock(QWidget *parent = nullptr);
    ~MultiplicationBlock() override;
    QString getLuaCodeLine() override;

private:
    Ui::MultiplicationBlock *ui;
};

#endif // MULTIPLICATIONBLOCK_H
