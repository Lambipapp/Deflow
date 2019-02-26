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
    projectPath->remove(tr("game.project"));
    qDebug() << *projectPath;

    if(projectPath->length() > 0){
        ui->fileTree->ShowTree(projectPath);
        StatusBar::instance->postMsg(tr("Opening project at: ")+projectPath, 2);


        GSSerializer gss(*projectPath); ////////////////SAVE

    }
    else
    {
        StatusBar::instance->postMsg(tr("Did not find project"), 2);
    }
}

