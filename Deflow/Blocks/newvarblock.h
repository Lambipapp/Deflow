#ifndef NEWVARBLOCK_H
#define NEWVARBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class NewVarBlock;
}

class NewVarBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit NewVarBlock(QWidget *parent = nullptr);
    ~NewVarBlock() override;
    QString getLuaCodeLine() override;
    QString GetVarName() const;

private:
    Ui::NewVarBlock *ui;
};

#endif // NEWVARBLOCK_H
