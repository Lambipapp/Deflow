#ifndef CONSTANTVARBLOCK_H
#define CONSTANTVARBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class ConstantVarBlock;
}

class ConstantVarBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit ConstantVarBlock(QWidget *parent = nullptr);
    ~ConstantVarBlock() override;
    QString getLuaCodeLine() override;
    bool isDigits(const QString &string) const;


private:
    Ui::ConstantVarBlock *ui;
};

#endif // CONSTANTVARBLOCK_H
