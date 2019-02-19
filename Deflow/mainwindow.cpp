#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    topbar = new TopBarController(menuBar(), this);
    topbar->SetUpMenu();
    canvas = new Canvas(300,200);
    centralWidget()->layout()->addWidget(canvas);



    for(int i = 0; i < 30; i++)
    {
        TestBlock *b = new TestBlock(canvas);
        canvas->blocks.push_back(b);
    }

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

    ui->fileTree->ShowTree(projectPath);
}

