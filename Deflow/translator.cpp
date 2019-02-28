#include "translator.h"
#include "canvas.h"
#include "blocks.h"
#include <QDebug>

Translator::Translator()
{
    TranslateAllGraphSpaces();
}


void Translator::TranslateAllGraphSpaces()
{
    QList<GraphSpace*> gs = Canvas::instance->GetGraphSpaces();
    //check input connectors, depth first search backwards until all connectors have been searched


    //DFS
    //using a vector for this is slow
    std::vector<ConnectorExecOut*> visited;
    std::vector<ConnectorExecOut*> discovered;


    discovered.push_back(gs[0]->startBlock->myExecOutConnectors[0]);



    ConnectorExecOut* current = nullptr;
    while(discovered.size() > 0)
    {
        current = discovered[discovered.size()-1];
        discovered.pop_back();

        visited.push_back(current);
        //search backwards for all dependencies

        if(current->next != nullptr)
        {
            BaseBlock* b = static_cast<BaseBlock*>(current->next->myBlock);
            for(unsigned int i = 0; i < b->myExecOutConnectors.size(); i++)
            {
                discovered.push_back(b->myExecOutConnectors[i]);
            }
        }
    }

    for(uint i = 0; i < visited.size(); i++)
    {
        qDebug() << visited[i]->myBlock->objectName();
    }

    delete this;

}
