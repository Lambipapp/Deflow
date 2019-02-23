#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>


namespace Ui {
class Connector;
}

class Connector : public QWidget
{
    Q_OBJECT
public:
    explicit Connector(QWidget *parent = nullptr);
    ~Connector() override;
    static Connector* selected;

private:
    Ui::Connector *ui;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // CONNECTOR_H