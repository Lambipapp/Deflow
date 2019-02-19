#include "openingdialog.h"
#include "ui_openingdialog.h"

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

}

void OpeningDialog::on_buttonBox_rejected()
{

}

void OpeningDialog::SetFile(const QString filename, const QString filepath)
{
    fileName = new QString(filename);
    filePath = new QString(filepath);
    ui->fileName->setText(filename);

}
