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
    ~SetVarBlock();
    QJsonObject GetJsonRepresentation();
    QString getLuaCodeLine();
    void ReLoadData(QJsonObject data);

private:
    Ui::SetVarBlock *ui;
};

#endif // SETVARBLOCK_H
