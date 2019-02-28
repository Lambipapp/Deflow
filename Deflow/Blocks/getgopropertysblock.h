#ifndef GETGOPROPERTYSBLOCK_H
#define GETGOPROPERTYSBLOCK_H

#include <QWidget>
#include "baseblock.h"
namespace Ui {
class GetGOPropertysBlock;
}

class GetGOPropertysBlock : public BaseBlock
{
    Q_OBJECT

public:
    explicit GetGOPropertysBlock(QWidget *parent = nullptr);
    ~GetGOPropertysBlock();
    QJsonObject GetJsonRepresentation();
    QString getLuaCodeLine();
    void ReLoadData(QJsonObject data);

private:
    Ui::GetGOPropertysBlock *ui;
};

#endif // GETGOPROPERTYSBLOCK_H
