#ifndef ADDBLOCK_H
#define ADDBLOCK_H

#include <QWidget>

namespace Ui {
class AddBlock;
}

class AddBlock : public QWidget
{
    Q_OBJECT

public:
    explicit AddBlock(QWidget *parent = nullptr);
    ~AddBlock();

private:
    Ui::AddBlock *ui;
};

#endif // ADDBLOCK_H
