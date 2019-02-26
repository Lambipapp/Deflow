#include "foldertree.h"
#include "ui_foldertree.h"
#include "filemanager.h"

FolderTree::FolderTree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FolderTree),
    od(new OpeningDialog(parent))
{
    ui->setupUi(this);
    folderModel = new QFileSystemModel();


    folderModel->setNameFilters(QStringList() << tr("*.script"));

}

FolderTree::~FolderTree()
{
    delete ui;
    delete od;
}
void FolderTree::ShowTree(QString* folderPath)
{

    folderModel->setRootPath(*folderPath);
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
    if(folderModel->fileName(index).contains(tr(".script")))
    {
        checkFile(folderModel->filePath(index), folderModel->fileName(index));
        StatusBar::instance->postMsg(tr("Opening ") + folderModel->fileName(index) , 2);
    }else
    {
        StatusBar::instance->postMsg(tr("Not a *.script-file"), 2);
    }
}

void FolderTree::checkFile(const QString &filePath,const QString &fileName)
{
    FileManager::fm->OpenFile(filePath,fileName);
}
////////////////////////////////////////////THIS IS GOING TO GET IMPLEMENTED IN ITS OWN CLASS LATER////////////////////////////////

