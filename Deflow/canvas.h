#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include "Blocks/baseblock.h"
#include "Blocks/printblock.h"
#include "graphspace.h"
#include <iostream>

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget* parent = nullptr);




    ~Canvas();
    static GraphSpace* currentGraphSpace;
    static Canvas* instance;

private:
    Ui::Canvas *ui;




protected:


public slots:
    //create block
//    template<class T>
//        void CreateBlock()
//        {
//            T *n = new T(currentCanvas);
//            //make sure we are creating a block
//            if(!n->inherits("BaseBlock"))
//            {
//                delete n;
//                return;
//            }
//            currentGraphSpace->blocks.push_back(n);
//        }

    void CreatePrintBlock(const QPoint &pos);
    void RemoveBlock(BaseBlock* block);
private slots:
    void on_FunctionTabs_currentChanged(int index);
};

#endif // CANVAS_H
