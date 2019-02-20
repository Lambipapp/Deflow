#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QWheelEvent>
#include "Blocks/baseblock.h"
#include "Blocks/printblock.h"
#include "graphspace.h"

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget* parent = nullptr);


    //create block
    template<class T>
        void CreateBlock()
        {
            T *n = new T(currentCanvas);
            //make sure we are creating a block
            if(!n->inherits("BaseBlock"))
            {
                delete n;
                return;
            }
            currentGraphSpace->blocks.push_back(n);
        }

    ~Canvas();
    static QWidget* currentCanvas;
    static GraphSpace* currentGraphSpace;

private:
    Ui::Canvas *ui;




protected:


private slots:
    void on_FunctionTabs_currentChanged(int index);
};

#endif // CANVAS_H
