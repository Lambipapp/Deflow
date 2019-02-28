#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "graphspace.h"
#include <QString>

class Translator
{
public:
    Translator();


    QString TranslateAllGraphSpaces();
    void TranslateGraphSpace(GraphSpace* gs, QString &gsCode);
    void AddFunctionNameToString(int i, QString &string);
};

#endif // TRANSLATOR_H
