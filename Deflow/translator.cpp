#include "translator.h"
#include "canvas.h"
#include <QDebug>

Translator::Translator()
{
    TranslateAllGraphSpaces();
}



void Translator::TranslateAllGraphSpaces()
{
    QList<GraphSpace*> gs = Canvas::instance->GetGraphSpaces();
    //check input connectors, depth first search backwards until all connectors have been searched





}
