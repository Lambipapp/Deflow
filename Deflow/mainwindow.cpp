#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    topbar = new TopBarController(menuBar(), this);
    topbar->SetUpMenu();
    setWindowTitle(tr("Deflow"));

    //create block example
    //ui->canvas->CreateBlock<PrintBlock>();
    //ui->canvas->CreateBlock<PrintBlock>();


    new FileManager();
    ui->canvas->CreateAddBlock(QPoint(100, 100));
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
    }
    else
    {
        StatusBar::instance->postMsg(tr("Did not find project"), 2);
    }
}

