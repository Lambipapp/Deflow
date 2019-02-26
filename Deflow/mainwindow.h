#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "topbarcontroller.h"
#include "canvas.h"
#include "Blocks.h"
#include "statusbar.h"
#include <QDebug>
#include "filemanager.h"

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
    StatusBar* sb;
};

#endif // MAINWINDOW_H
