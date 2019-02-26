#ifndef CONDITIONALBLOCK_H
#define CONDITIONALBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class ConditionalBlock;
}

class ConditionalBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit ConditionalBlock(QWidget *parent = nullptr);
    ~ConditionalBlock() override;

    QString getLuaCodeLine() override;
    QJsonObject GetJsonRepresentation() override;

private:
    Ui::ConditionalBlock *ui;
};

#endif // CONDITIONALBLOCK_H
