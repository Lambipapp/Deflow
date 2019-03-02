#ifndef AUTOUPDATECOMBOBOX_H
#define AUTOUPDATECOMBOBOX_H

#include <QWidget>
#include <QComboBox>
#include "filemanager.h"


namespace Ui {
class AutoUpdateComboBox;
}

class AutoUpdateComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit AutoUpdateComboBox(QWidget *parent = nullptr);
    ~AutoUpdateComboBox();
    void UpdateContents();

private:
    Ui::AutoUpdateComboBox *ui;
    QString inputFileContents;
    QStringList InterpretInputFileContents();
    void SetActionBoxContent(const QStringList &inputKeys);

    QStringList keys;
public:
 virtual void showPopup() override;
};

#endif // AUTOUPDATECOMBOBOX_H
