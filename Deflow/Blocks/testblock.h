#ifndef TESTBLOCK_H
#define TESTBLOCK_H

#include <QWidget>

namespace Ui {
class TestBlock;
}

class TestBlock : public QWidget
{
    Q_OBJECT

public:
    explicit TestBlock(QWidget *parent = nullptr);
    ~TestBlock();

    static TestBlock* selectedBlock;
    QPoint mouseOffset;

private:
    Ui::TestBlock *ui;
    QPoint dragStartPosition;


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // TESTBLOCK_H
