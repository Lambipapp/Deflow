#ifndef ACQUIREINPUTBLOCK_H
#define ACQUIREINPUTBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class AcquireInputBlock;
}

class AcquireInputBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit AcquireInputBlock(QWidget *parent = nullptr);
    ~AcquireInputBlock() override;

    QString getLuaCodeLine() override;
    QJsonObject GetJsonRepresentation() override;
    void ReLoadData(QJsonObject data) override;

private:
    Ui::AcquireInputBlock *ui;
};

#endif // ACQUIREINPUTBLOCK_H
