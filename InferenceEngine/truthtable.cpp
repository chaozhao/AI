#include "TruthTable.h"

TruthTable::TruthTable(KnowledgeBase *_kb)
{
    kb = _kb;
    for(unsigned i = 0;i<kb->getClause().size();i++ )
    {
        addSymbol(kb->getClause(i).getHead());

        for(unsigned j =0;j<kb->getClause(i).getBody().size();j++)
        {

        }

    }
}

TruthTable::~TruthTable()
{
    //dtor
}


void TruthTable::addSymbol(Symbol aSymbol)
{
    //TODO check if is unique
}
