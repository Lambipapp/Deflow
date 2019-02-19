#include "statusbar.h"

StatusBar* StatusBar::instance = nullptr;

StatusBar::StatusBar(QStatusBar* statusbar):
    statusBar(statusbar)
{
    if(instance == nullptr)
        instance = this;
    else
        delete(this);

}

void StatusBar::postMsg(const QString &message, int second)
{
    statusBar->clearMessage();
    statusBar->showMessage(message, second*1000);
}
