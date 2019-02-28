#ifndef CONNECTORIN_H
#define CONNECTORIN_H

#include <QWidget>
#include "Connectors/connector.h"
#include "connectorout.h"

namespace Ui {
class ConnectorIn;
}

class ConnectorIn : public Connector
{
    Q_OBJECT

public:
    explicit ConnectorIn(QWidget *parent = nullptr);
    ~ConnectorIn() override;

    ConnectorOut* input = nullptr;
    void LoseConnection(Connector* c) override;
    void BindConnection(Connector* c) override;
    QJsonObject GetJsonRepresentation() override;
private:
    Ui::ConnectorIn *ui;
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // CONNECTORIN_H
