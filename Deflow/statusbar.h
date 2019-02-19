#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QStatusBar>

class StatusBar
{
public:
    StatusBar(QStatusBar* statusbar);
    static StatusBar* instance;
    void postMsg(const QString &message, int second);

private:
    QStatusBar* statusBar;
};

#endif // STATUSBAR_H
