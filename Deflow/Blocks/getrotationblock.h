#ifndef GETROTATIONBLOCK_H
#define GETROTATIONBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class GetRotationBlock;
}

class GetRotationBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit GetRotationBlock(QWidget *parent = nullptr);
    ~GetRotationBlock() override;
    QString getLuaCodeLine() override;

private:
    Ui::GetRotationBlock *ui;
};

#endif // GETROTATIONBLOCK_H
