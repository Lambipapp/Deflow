#ifndef CONNECTOREXEC_H
#define CONNECTOREXEC_H

#include <QWidget>
#include "connector.h"


namespace Ui {
class ConnectorExec;
}

class ConnectorExec : public Connector
{
    Q_OBJECT

public:
    explicit ConnectorExec(QWidget *parent = nullptr);
    ~ConnectorExec();

private:
    Ui::ConnectorExec *ui;
};

#endif // CONNECTOREXEC_H
