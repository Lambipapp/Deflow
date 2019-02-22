#ifndef CONNECTOROUT_H
#define CONNECTOROUT_H

#include <QWidget>
#include "connector.h"
#include <vector>
#include "connectorin.h"


namespace Ui {
class ConnectorOut;
}
class ConnectorOut : public Connector
{
public:
    explicit ConnectorOut(QWidget* parent);

    std::vector<ConnectorIn*> connections;

private:
    Ui::ConnectorOut* ui;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

};

#endif // CONNECTOROUT_H
