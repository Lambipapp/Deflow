#ifndef CANVAS_TABS_H
#define CANVAS_TABS_H

#include <QWidget>

namespace Ui {
class Canvas_tabs;
}

class Canvas_tabs : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas_tabs(QWidget *parent = nullptr);
    ~Canvas_tabs();

private:
    Ui::Canvas_tabs *ui;
};

#endif // CANVAS_TABS_H
