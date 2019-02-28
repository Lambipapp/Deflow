#include "connectorexecin.h"
#include "connectorexecout.h"
#include "ui_connectorexecin.h"
#include "canvas.h"


ConnectorExecIn::ConnectorExecIn(QWidget *parent) :
    Connector(parent),
    ui(new Ui::ConnectorExecIn)
{
    ui->setupUi(this);
    ui->Arrow->setAttribute(Qt::WA_TransparentForMouseEvents);
    myType = NodeType::execIn;
}

ConnectorExecIn::~ConnectorExecIn()
{
    LoseConnection(this);
    delete ui;
}

void ConnectorExecIn::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        clickedConnector = this;
    else if(event->button() == Qt::RightButton)
    {
        LoseConnection(this);
    }
}
void ConnectorExecIn::mouseReleaseEvent(QMouseEvent* event)
{
    clickedConnector = nullptr;
    QWidget* widget = qApp->widgetAt(event->globalPos());

    if(widget == this)
    {
        Canvas::lineRenderer->update();
        return;
    }

    if(widget->inherits("Connector"))
    {
        Connector* temp = static_cast<Connector*>(widget);
        if(temp->myType == NodeType::execOut)
        {
            if(temp->myBlock == myBlock){
                Canvas::lineRenderer->update();
                return;
            }
            ConnectorExecOut* c = static_cast<ConnectorExecOut*>(widget);
            c->next = this;

            c->BindConnection(this);
            BindConnection(c);
        }
    }
    Canvas::lineRenderer->update();
}
void ConnectorExecIn::mouseMoveEvent(QMouseEvent *event)
{
    Canvas::lineRenderer->update();
}

void ConnectorExecIn::LoseConnection(Connector* c)
{
    if(c == this)
    {
        for(unsigned int i = 0; i < connected.size(); i++)
        {
            connected[i]->LoseConnection(this);
        }
        connected.clear();
    }
    else
    {for(unsigned int i = 0; i < connected.size(); i++)
        {
            if(c == connected[i])
            {
                //c->LoseConnection(this);
                connected.erase(connected.begin()+i);
            }
        }
    }
    ui->Arrow->setStyleSheet(tr("background-image: url(:/new/prefix1/Arrow.png);"));
}

void ConnectorExecIn::BindConnection(Connector* c)
{
    if(!(std::find(connected.begin(), connected.end(), c) != connected.end())) {
        connected.push_back(c);
    }
    ui->Arrow->setStyleSheet(tr("background-image: url(:/new/prefix1/Arrow-filled.png);"));
}
QJsonObject ConnectorExecIn::GetJsonRepresentation()
{
    QJsonObject o;

    o.insert("myType", myType);
    o.insert("myID", id);

    return o;
}

