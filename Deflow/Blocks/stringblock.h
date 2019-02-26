#ifndef STRINGBLOCK_H
#define STRINGBLOCK_H

#include <QWidget>
#include "Blocks/baseblock.h"

namespace Ui {
class StringBlock;
}

class StringBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit StringBlock(QWidget *parent = nullptr);
    ~StringBlock();
    QString getLuaCodeLine() override;
    QJsonObject GetJsonRepresentation() override;
private:
    Ui::StringBlock *ui;
};

#endif // STRINGBLOCK_H
