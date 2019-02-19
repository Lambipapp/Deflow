#include "foldertreeview.h"
#include <QVBoxLayout>
folderTreeView::folderTreeView(QWidget *parent) :
    QWidget(parent)
{
    tree = new QTreeView(this);
    setLayout(new QVBoxLayout());
    layout()->addWidget(tree);
    folderModel = new QFileSystemModel();



}
void folderTreeView::ShowTree(QString* folderPath)
{
    folderModel->setRootPath(*folderPath);//model->setRootPath(projectPath);
    tree->setModel(folderModel);
    tree->setRootIndex(folderModel->index(*folderPath));

    tree->hideColumn(1);
    tree->hideColumn(2);
    tree->hideColumn(3);
}
