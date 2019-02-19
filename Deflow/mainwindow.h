#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "topbarcontroller.h"
#include "foldertreeview.h"
#include "canvas.h"
#include "testblock.h"
#include <QSplitter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString* projectPath;

private slots:
    void OpenFileDialog();

private:
    Ui::MainWindow *ui;
    TopBarController* topbar;
    Canvas *canvas;
    folderTreeView* fileTree;
};

#endif // MAINWINDOW_H
