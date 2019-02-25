#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QApplication>



class Connector : public QWidget
{
    Q_OBJECT
public:
    explicit Connector(QWidget *parent = nullptr);
    enum NodeType {execIn, execOut, varIn, varOut};
signals:

public slots:

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
public:
    NodeType myType;
    QWidget *myBlock = nullptr;
};

#endif // CONNECTOR_H
