#ifndef ACQUIREINPUTBLOCK_H
#define ACQUIREINPUTBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class AcquireInputBlock;
}

class AcquireInputBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit AcquireInputBlock(QWidget *parent = nullptr);
    ~AcquireInputBlock();

    QString getLuaCodeLine() override;

private:
    Ui::AcquireInputBlock *ui;
};

#endif // ACQUIREINPUTBLOCK_H
