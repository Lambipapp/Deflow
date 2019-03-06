#ifndef AUTOUPDATECOMBOBOX_H
#define AUTOUPDATECOMBOBOX_H

#include <QWidget>
#include <QComboBox>
#include "filemanager.h"
#include "canvas.h"


namespace Ui {
class AutoUpdateComboBox;
}

class AutoUpdateComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit AutoUpdateComboBox(QWidget *parent = nullptr);
    ~AutoUpdateComboBox();
    void SetActionBoxContent(const QStringList &inputKeys);
    BaseBlock* myBlock;

private:
    Ui::AutoUpdateComboBox *ui;

    QStringList content;
public:
 virtual void showPopup() override;
};

#endif // AUTOUPDATECOMBOBOX_H
