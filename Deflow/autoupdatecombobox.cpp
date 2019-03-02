#include "autoupdatecombobox.h"
#include "ui_autoupdatecombobox.h"


AutoUpdateComboBox::AutoUpdateComboBox(QWidget *parent) :
    QComboBox(parent),
    ui(new Ui::AutoUpdateComboBox)
{
    ui->setupUi(this);
    UpdateContents();
}

AutoUpdateComboBox::~AutoUpdateComboBox()
{
    delete ui;
}


void AutoUpdateComboBox::showPopup()
{
    UpdateContents();
    QComboBox::showPopup();
}


void AutoUpdateComboBox::UpdateContents()
{
    FileManager::fm->FindAndReadInputFile(inputFileContents);
    keys = InterpretInputFileContents();
    SetActionBoxContent(keys);
}


QStringList AutoUpdateComboBox::InterpretInputFileContents()
{
    if(inputFileContents == "")
        return QStringList();

    QRegExp rx("\\n");
    QStringList query = inputFileContents.split(rx);

    QStringList actions;
    for(int i = 0; i < query.size(); i++)
    {
        //i dont know what this does. but it works so i dont care
        if(query[i].contains("action:"))
        {
            QRegExp rx2("action:|\\\"");
            QStringList tmp = query[i].split(rx2);
            actions.push_back(tmp[2]);
        }
    }
    return actions;
}


void AutoUpdateComboBox::SetActionBoxContent(const QStringList &inputKeys)
{
    clear();
    if(inputKeys.size() == 0)
    {
        addItem("No Input Keys Detected");
    }

    addItems(inputKeys);
}
