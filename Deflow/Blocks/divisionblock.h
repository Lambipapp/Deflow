#ifndef DIVISIONBLOCK_H
#define DIVISIONBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class DivisionBlock;
}

class DivisionBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit DivisionBlock(QWidget *parent = nullptr);
    ~DivisionBlock() override;
     QJsonObject GetJsonRepresentation() override;
     QString getLuaCodeLine() override;
     void ReLoadData(QJsonObject data) override;

private:
    Ui::DivisionBlock *ui;
};

#endif // DIVISIONBLOCK_H
