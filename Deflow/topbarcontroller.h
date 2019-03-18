#ifndef TOPBARCONTROLLER_H
#define TOPBARCONTROLLER_H

#include <QMainWindow>
#include <QMenuBar>
#include "aboutdialog.h"

class TopBarController : public QObject
{
    Q_OBJECT

public:
    TopBarController(QMenuBar* menu,QMainWindow* mainwindow);
    ~TopBarController();
    void SetUpMenu();


private:
    void FileMenu_Add();
    void AboutMenu_Add();
    void FileMenu_Populate();
    void AboutMenu_Populate();

    QMenuBar* menuBar;
    QMainWindow* mainWindow;
    QMenu* fileMenu;
    QMenu* aboutMenu;
    AboutDialog* ad;

public slots:
    void openAboutWindow();


};

#endif // TOPBARCONTROLLER_H
