#ifndef F_H
#define F_H

#include <QFrame>

namespace Ui {
class F;
}

class F : public QFrame
{
    Q_OBJECT

public:
    explicit F(QWidget *parent = nullptr);
    ~F();

private:
    Ui::F *ui;
};

#endif // F_H
