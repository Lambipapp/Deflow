#include "autoupdatecombobox.h"
#include "ui_autoupdatecombobox.h"


AutoUpdateComboBox::AutoUpdateComboBox(QWidget *parent) :
    QComboBox(parent),
    ui(new Ui::AutoUpdateComboBox)
{
    ui->setupUi(this);
    //UpdateContents();
}

AutoUpdateComboBox::~AutoUpdateComboBox()
{
    delete ui;
}


void AutoUpdateComboBox::showPopup()
{
    SetActionBoxContent(myBlock->UpdateComboBoxContents());
    QComboBox::showPopup();
}

void AutoUpdateComboBox::SetActionBoxContent(const QStringList &inputKeys)
{
    clear();
    if(inputKeys.size() == 0)
    {
        addItem("---");
    }

    addItems(inputKeys);
}
