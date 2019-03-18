#include "topbarcontroller.h"

TopBarController::TopBarController(QMenuBar* menu, QMainWindow* mainwindow):
    menuBar(menu), mainWindow(mainwindow)
{
    ad = new AboutDialog();
}

TopBarController::~TopBarController()
{
    delete ad;
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

void TopBarController::openAboutWindow()
{
    ad->exec();
}


void TopBarController::AboutMenu_Populate()
{
    QAction* aboutAction = aboutMenu->addAction(QMenuBar::tr("About Deflow"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(openAboutWindow()));
    aboutMenu->addSeparator();
    QAction* lisenceAction = aboutMenu->addAction(QMenuBar::tr("License"));
}



