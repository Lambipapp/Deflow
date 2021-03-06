#ifndef OPENINGDIALOG_H
#define OPENINGDIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class OpeningDialog;
}

class OpeningDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OpeningDialog(QWidget *parent = nullptr);
    ~OpeningDialog();
    void SetFile(const QString filename);
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::OpeningDialog *ui;
    QString* fileName;
};

#endif // OPENINGDIALOG_H
