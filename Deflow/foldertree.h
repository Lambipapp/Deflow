#ifndef FOLDERTREE_H
#define FOLDERTREE_H

#include <QWidget>
#include <QTreeView>
#include <QFileSystemModel>
#include <QAbstractButton>

#include <iostream>

namespace Ui {
class FolderTree;
}

class FolderTree : public QWidget
{
    Q_OBJECT

public:
    explicit FolderTree(QWidget *parent = nullptr);
    ~FolderTree();
    void ShowTree(QString* folderPath);

private slots:
    void on_toggleButton_clicked();

    void on_tree_doubleClicked(const QModelIndex &index);

private:
    Ui::FolderTree *ui;
    QFileSystemModel* folderModel;
    bool minimized = false;
};

#endif // FOLDERTREE_H
