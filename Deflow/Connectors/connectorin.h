#ifndef CONNECTORIN_H
#define CONNECTORIN_H

#include <QWidget>

namespace Ui {
class ConnectorIn;
}

class ConnectorIn : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectorIn(QWidget *parent = nullptr);
    ~ConnectorIn();

private:
    Ui::ConnectorIn *ui;
};

#endif // CONNECTORIN_H
