#ifndef SETVARBLOCK_H
#define SETVARBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class SetVarBlock;
}

class SetVarBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit SetVarBlock(QWidget *parent = nullptr);
    ~SetVarBlock() override;
    QString getLuaCodeLine() override;

private:
    Ui::SetVarBlock *ui;

protected:
    virtual QStringList UpdateComboBoxContents() override;
};

#endif // SETVARBLOCK_H
