#ifndef CONNECTOREXECOUT_H
#define CONNECTOREXECOUT_H

#include <QWidget>
#include "Connectors/connector.h"
#include "Connectors/connectorexecin.h"


namespace Ui {
class ConnectorExecOut;
}

class ConnectorExecOut : public Connector
{
    Q_OBJECT
public:
    explicit ConnectorExecOut(QWidget *parent = nullptr);
    ~ConnectorExecOut();
    ConnectorExecIn* next = nullptr;
    void LoseConnection(Connector* c) override;
    void BindConnection(Connector* c) override;
    QJsonObject GetJsonRepresentation() override;

private:
    Ui::ConnectorExecOut *ui;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // CONNECTOREXECOUT_H
