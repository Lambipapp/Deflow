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
    QJsonObject GetJsonRepresentation() override;
    void ReLoadData(QJsonObject data) override;

private:
    Ui::ConstantVarBlock *ui;
};

#endif // CONSTANTVARBLOCK_H