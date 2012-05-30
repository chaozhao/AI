#ifndef TRUTHTABLE_H
#define TRUTHTABLE_H

#include "symbol.h"
#include <vector>
#include "KnowledgeBase.h"


class TruthTable
{
private:
    KnowledgeBase *kb;
    vector<vector<bool> >     tt;
public:
    TruthTable(KnowledgeBase *kb);
    ~TruthTable();
    void addSymbol(Symbol aSymbol);
    void addSymbol(vector<Symbol> symbols);

};

#endif // TRUTHTABLE_H
