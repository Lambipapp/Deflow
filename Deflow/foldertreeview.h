#ifndef FOLDERTREEVIEW_H
#define FOLDERTREEVIEW_H

#include <QWidget>
#include <QTreeView>
#include <QFileSystemModel>

class folderTreeView : public QWidget
{
    Q_OBJECT
public:
    explicit folderTreeView(QWidget *parent = nullptr);
    void ShowTree(QString* folderPath);
signals:

public slots:

private:
    QTreeView* tree;
    QFileSystemModel* folderModel;
};

#endif // FOLDERTREEVIEW_H
