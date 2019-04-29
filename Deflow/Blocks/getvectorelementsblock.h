#ifndef GETVECTORELEMENTSBLOCK_H
#define GETVECTORELEMENTSBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class GetVectorElementsBlock;
}

class GetVectorElementsBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit GetVectorElementsBlock(QWidget *parent = nullptr);
    ~GetVectorElementsBlock() override;
    QString getLuaCodeLine() override;

private:
    Ui::GetVectorElementsBlock *ui;
};

#endif // GETVECTORELEMENTSBLOCK_H
