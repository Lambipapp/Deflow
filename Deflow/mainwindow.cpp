#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    topbar = new TopBarController(menuBar(), this);
    topbar->SetUpMenu();

    //create block example
    ui->canvas->CreateBlock<PrintBlock>();

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
    std::cout << projectPath->toStdString() << std::endl;

    if(projectPath->length() > 0)
        ui->fileTree->ShowTree(projectPath);
}

