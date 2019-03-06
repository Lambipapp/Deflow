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
    virtual QStringList UpdateComboBoxContents() override;

private slots:
    void on_ActionNameBox_activated(const QString &arg1);

private:
    Ui::InputBlock *ui;

    QString DecodeAction() const;
    QString inputFileContents;
    QStringList InterpretInputFileContents();

protected:
    void mousePressEvent(QMouseEvent* event) override;


};

#endif // INPUTBLOCK_H
