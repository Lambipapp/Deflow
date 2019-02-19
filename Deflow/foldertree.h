#ifndef FOLDERTREE_H
#define FOLDERTREE_H

#include <QWidget>
#include <QTreeView>
#include <QFileSystemModel>
#include <QAbstractButton>
#include <QSortFilterProxyModel>
#include "mainwindow.h"
#include <statusbar.h>

#include "openingdialog.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

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


    ////TEMP
    void checkFile(const QString &filePath,const QString &fileName);

private:
    Ui::FolderTree *ui;
    QFileSystemModel* folderModel;
    bool minimized = false;
    OpeningDialog* od;
};

#endif // FOLDERTREE_H
