#ifndef GETPOSITIONBLOCK_H
#define GETPOSITIONBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class GetPositionBlock;
}

class GetPositionBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit GetPositionBlock(QWidget *parent = nullptr);
    ~GetPositionBlock() override;
    QString getLuaCodeLine() override;

private:
    Ui::GetPositionBlock *ui;
};

#endif // GETPOSITIONBLOCK_H
