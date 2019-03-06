#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include "blocks.h"
#include "graphspace.h"
#include <iostream>
#include "linerenderer.h"
#include <QJsonDocument>

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget* parent = nullptr);

    static LineRenderer* lineRenderer;
    QStringList GetAllVariables() const;


    ~Canvas();
    static GraphSpace* currentGraphSpace;
    static Canvas* instance;
    QList<GraphSpace*> GetGraphSpaces();


private:
    Ui::Canvas *ui;
    void OpenFile();
    void SaveVisualCode();
    QList<GraphSpace*> gSpaces;

protected:


public slots:

    //void RemoveBlock(BaseBlock* block);
private slots:
    void on_FunctionTabs_currentChanged(int index);
};

#endif // CANVAS_H
