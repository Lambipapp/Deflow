#ifndef INPUTBLOCK_H
#define INPUTBLOCK_H

#include <QWidget>
#include "baseblock.h"

namespace Ui {
class InputBlock;
}

class InputBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit InputBlock(QWidget *parent = nullptr);
    ~InputBlock()override;
    QString getLuaCodeLine() override;
    QJsonObject GetJsonRepresentation() override;
    void ReLoadData(QJsonObject data) override;

private slots:
    void on_ActionNameBox_activated(const QString &arg1);

    void on_ActionNameBox_highlighted(const QString &arg1);

private:
    Ui::InputBlock *ui;
};

#endif // INPUTBLOCK_H
