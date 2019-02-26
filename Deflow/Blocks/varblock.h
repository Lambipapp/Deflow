#ifndef VARBLOCK_H
#define VARBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class VarBlock;
}

class VarBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit VarBlock(QWidget *parent = nullptr);
    ~VarBlock() override;
    QString getLuaCodeLine() override;
    QJsonObject GetJsonRepresentation() override;

private:
    Ui::VarBlock *ui;
};

#endif // VARBLOCK_H
