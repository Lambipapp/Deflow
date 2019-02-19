#ifndef TOPBARCONTROLLER_H
#define TOPBARCONTROLLER_H

#include <QMainWindow>
#include <QMenuBar>

#include <iostream>

class TopBarController
{
public:
    TopBarController(QMenuBar* menu,QMainWindow* mainwindow);
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

};

#endif // TOPBARCONTROLLER_H
