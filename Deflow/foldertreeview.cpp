#include "foldertreeview.h"
#include <QVBoxLayout>
folderTreeView::folderTreeView(QWidget *parent) :
    QWidget(parent)
{
    tree = new QTreeView(this);
    setLayout(new QVBoxLayout());
    layout()->addWidget(tree);
}
