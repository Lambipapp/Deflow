#ifndef FOLDERTREEVIEW_H
#define FOLDERTREEVIEW_H

#include <QWidget>
#include <QTreeView>

class folderTreeView : public QWidget
{
    Q_OBJECT
public:
    explicit folderTreeView(QWidget *parent = nullptr);

signals:

public slots:

private:
    QTreeView* tree;
};

#endif // FOLDERTREEVIEW_H
