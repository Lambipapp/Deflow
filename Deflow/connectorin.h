#ifndef CONNECTORIN_H
#define CONNECTORIN_H

#include <QWidget>
#include "connector.h"

namespace Ui {
class ConnectorIn;
}

class ConnectorIn : public Connector
{
public:
    ConnectorIn(QWidget* parent);

private:
    Ui::ConnectorIn* ui;
};

#endif // CONNECTORIN_H
