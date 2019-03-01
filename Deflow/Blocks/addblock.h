#ifndef ADDBLOCK_H
#define ADDBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class AddBlock;
}

class AddBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit AddBlock(QWidget *parent = nullptr);
    ~AddBlock() override;

    QString getLuaCodeLine() override;
    QJsonObject GetJsonRepresentation() override;
    void ReLoadData(QJsonObject data) override;

private:
    Ui::AddBlock *ui;


};

#endif // ADDBLOCK_H
