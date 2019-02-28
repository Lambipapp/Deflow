#ifndef CONNECTOROUT_H
#define CONNECTOROUT_H

#include <QWidget>
#include "Connectors/connector.h"

namespace Ui {
class ConnectorOut;
}

class ConnectorOut : public Connector
{
    Q_OBJECT

public:
    explicit ConnectorOut(QWidget *parent = nullptr);
    ~ConnectorOut()override;
    void LoseConnection(Connector* c) override;
    void BindConnection(Connector* c) override;
    QJsonObject GetJsonRepresentation() override;
private:
    Ui::ConnectorOut *ui;
protected:
    std::vector<Connector*> connected;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;


};

#endif // CONNECTOROUT_H
