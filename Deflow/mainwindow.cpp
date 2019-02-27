#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gsserializer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    topbar = new TopBarController(menuBar(), this);
    topbar->SetUpMenu();
    setWindowTitle(tr("Deflow"));



    new FileManager();
    sb = new StatusBar(ui->statusBar);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::OpenFileDialog()
{

    QFileDialog fileDialog;
    QString fileName = fileDialog.getOpenFileName(this, tr("Select Defold Project"), "/home", tr("Project (*.project)"));
    projectPath = new QString(fileName);

    if(projectPath->contains(tr("game.project")))
    {
        projectPath->remove(tr("game.project"));
        ui->fileTree->ShowTree(projectPath);
        StatusBar::instance->postMsg(tr("Opening project at: ")+projectPath, 2);
        FileManager::fm->SetGSS(new GSSerializer(*projectPath));
    }
    else
    {
        StatusBar::instance->postMsg(tr("Did not find project"), 2);
    }
}

