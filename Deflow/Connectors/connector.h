#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QApplication>
#include <vector>


class Connector : public QWidget
{
    Q_OBJECT
public:
    explicit Connector(QWidget *parent = nullptr);
    ~Connector() override;
    enum NodeType {execIn, execOut, varIn, varOut};

    static Connector *clickedConnector;
    NodeType myType;
    QWidget *myBlock = nullptr;
    virtual void LoseConnection(Connector* c) = 0;
    virtual void BindConnection(Connector* c) = 0;
    int id;
    virtual QJsonObject GetJsonRepresentation() = 0;

signals:

public slots:

protected:
    static int cids;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
public:

};

#endif // CONNECTOR_H
