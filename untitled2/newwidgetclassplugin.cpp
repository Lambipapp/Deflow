#include "newwidgetclass.h"
#include "newwidgetclassplugin.h"

#include <QtPlugin>

newwidgetclassPlugin::newwidgetclassPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void newwidgetclassPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool newwidgetclassPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *newwidgetclassPlugin::createWidget(QWidget *parent)
{
    return new newwidgetclass(parent);
}

QString newwidgetclassPlugin::name() const
{
    return QLatin1String("newwidgetclass");
}

QString newwidgetclassPlugin::group() const
{
    return QLatin1String("");
}

QIcon newwidgetclassPlugin::icon() const
{
    return QIcon();
}

QString newwidgetclassPlugin::toolTip() const
{
    return QLatin1String("");
}

QString newwidgetclassPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool newwidgetclassPlugin::isContainer() const
{
    return false;
}

QString newwidgetclassPlugin::domXml() const
{
    return QLatin1String("<widget class=\"newwidgetclass\" name=\"newwidgetclass\">\n</widget>\n");
}

QString newwidgetclassPlugin::includeFile() const
{
    return QLatin1String("newwidgetclass.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(newwidgetclassplugin, newwidgetclassPlugin)
#endif // QT_VERSION < 0x050000
