#ifndef CONNECTOROUT_H
#define CONNECTOROUT_H

#include <QWidget>

namespace Ui {
class ConnectorOut;
}

class ConnectorOut : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectorOut(QWidget *parent = nullptr);
    ~ConnectorOut();

private:
    Ui::ConnectorOut *ui;
};

#endif // CONNECTOROUT_H
