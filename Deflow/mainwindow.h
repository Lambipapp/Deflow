#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "topbarcontroller.h"

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
};

#endif // MAINWINDOW_H
