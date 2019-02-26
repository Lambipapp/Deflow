#include "openingdialog.h"
#include "ui_openingdialog.h"
#include "filemanager.h"

OpeningDialog::OpeningDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpeningDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    setWindowTitle(tr("Warning"));
}

OpeningDialog::~OpeningDialog()
{
    delete ui;
}

void OpeningDialog::on_buttonBox_accepted()
{
    //open file
}

void OpeningDialog::on_buttonBox_rejected()
{
    //do nothing
}

void OpeningDialog::SetFile(const QString filename)
{
    fileName = new QString(filename);
    ui->fileName->setText(filename);

}
