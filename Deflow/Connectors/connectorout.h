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
    void LoseConnection() override;
    void BindConnection() override;
private:
    Ui::ConnectorOut *ui;
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;


};

#endif // CONNECTOROUT_H
