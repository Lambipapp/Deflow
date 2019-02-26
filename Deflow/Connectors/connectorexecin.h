#ifndef CONNECTOREXECIN_H
#define CONNECTOREXECIN_H

#include <QWidget>
#include "Connectors/connector.h"

namespace Ui {
class ConnectorExecIn;
}

class ConnectorExecIn : public Connector
{
    Q_OBJECT

public:
    explicit ConnectorExecIn(QWidget *parent = nullptr);
    ~ConnectorExecIn() override;
    void LoseConnection() override;
    void BindConnection() override;
    QJsonObject GetJsonRepresentation() override;
private:
    Ui::ConnectorExecIn *ui;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;


};

#endif // CONNECTOREXECIN_H
