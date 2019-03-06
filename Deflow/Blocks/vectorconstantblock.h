#ifndef VECTORCONSTANTBLOCK_H
#define VECTORCONSTANTBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class VectorConstantBlock;
}

class VectorConstantBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit VectorConstantBlock(QWidget *parent = nullptr);
    ~VectorConstantBlock() override;
    QString getLuaCodeLine() override;


private:
    Ui::VectorConstantBlock *ui;
};

#endif // VECTORCONSTANTBLOCK_H
