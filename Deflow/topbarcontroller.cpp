#include "topbarcontroller.h"

TopBarController::TopBarController(QMenuBar* menu, QMainWindow* mainwindow):
    menuBar(menu), mainWindow(mainwindow)
{

}

void TopBarController::SetUpMenu()
{
    FileMenu_Add();
    FileMenu_Populate();

    AboutMenu_Add();
    AboutMenu_Populate();
}

void TopBarController::FileMenu_Add()
{
    fileMenu = menuBar->addMenu(QMenuBar::tr("File"));
}

void TopBarController::AboutMenu_Add()
{
    aboutMenu = menuBar->addMenu(QMenuBar::tr("About"));
}

void TopBarController::FileMenu_Populate()
{
    fileMenu->addAction(QMenuBar::tr("Open Defold Project"),mainWindow, SLOT(OpenFileDialog()));
}

void TopBarController::AboutMenu_Populate()
{
    aboutMenu->addAction(QMenuBar::tr("About Deflow"));
    aboutMenu->addSeparator();
    aboutMenu->addAction(QMenuBar::tr("License"));
}


