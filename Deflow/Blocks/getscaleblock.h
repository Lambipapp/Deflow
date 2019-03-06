#ifndef GETSCALEBLOCK_H
#define GETSCALEBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class GetScaleBlock;
}

class GetScaleBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit GetScaleBlock(QWidget *parent = nullptr);
    ~GetScaleBlock() override;
    QString getLuaCodeLine() override;

private:
    Ui::GetScaleBlock *ui;
};

#endif // GETSCALEBLOCK_H
