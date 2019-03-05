#ifndef SETGOPROPERTYSBLOCK_H
#define SETGOPROPERTYSBLOCK_H

#include <QWidget>

#include "baseblock.h"
namespace Ui {
class SetGOPropertysBlock;
}

class SetGOPropertysBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit SetGOPropertysBlock(QWidget *parent = nullptr);
    ~SetGOPropertysBlock() override;
    QString getLuaCodeLine()override;

private:
    Ui::SetGOPropertysBlock *ui;
};

#endif // SETGOPROPERTYSBLOCK_H
