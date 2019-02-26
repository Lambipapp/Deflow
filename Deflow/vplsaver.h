#ifndef VPLSAVER_H
#define VPLSAVER_H

#include <QWidget>
#include <QDataStream>
#include "blocks.h"
#include "canvas.h"
#include "graphspace.h"


class VPLSaver
{
public:
    VPLSaver();
    ~VPLSaver();

    QString* openProjectPath;
};

#endif // VPLSAVER_H
