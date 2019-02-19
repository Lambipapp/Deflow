#include "foldertree.h"
#include "ui_foldertree.h"

FolderTree::FolderTree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FolderTree)
{
    ui->setupUi(this);
    folderModel = new QFileSystemModel();

}

FolderTree::~FolderTree()
{
    delete ui;
}
void FolderTree::ShowTree(QString* folderPath)
{
    folderModel->setRootPath(*folderPath);//model->setRootPath(projectPath);
    ui->tree->setModel(folderModel);
    ui->tree->setRootIndex(folderModel->index(*folderPath));

    ui->tree->hideColumn(1);
    ui->tree->hideColumn(2);
    ui->tree->hideColumn(3);
}

void FolderTree::on_toggleButton_clicked()
{
    if(minimized)
    {
        this->setMaximumWidth(300);
        ui->toggleButton->setText(tr("Hide"));
        ui->tree->setEnabled(minimized);
    }
    else
    {
        ui->toggleButton->setText(tr("Show"));
        this->setMaximumWidth(50);
        ui->tree->setEnabled(minimized);
    }
    minimized = !minimized;
}

void FolderTree::on_tree_doubleClicked(const QModelIndex &index)
{
    std::cout << folderModel->fileName(index).toStdString() << std::endl;
}
