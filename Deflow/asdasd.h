#ifndef ASDASD_H
#define ASDASD_H

#include <QFrame>

namespace Ui {
class asdasd;
}

class asdasd : public QFrame
{
    Q_OBJECT

public:
    explicit asdasd(QWidget *parent = nullptr);
    ~asdasd();

private:
    Ui::asdasd *ui;
};

#endif // ASDASD_H
