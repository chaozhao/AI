#ifndef BACKWARDCHAIN_H
#define BACKWARDCHAIN_H

#include "knowledgebase.h"
#include "symbol.h"
#include <vector>
#include <stack>

class BackwardChain
{
private:
    KnowledgeBase *kb;
    stack<Symbol> fringe;

public:
    BackwardChain(KnowledgeBase *kb);
    bool solve();
    void printSolution();
    Symbol findSubgoal(Symbol head);   
    void pushToFringe(Symbol aSymbol);
    vector<Symbol> findSubgoals(Symbol aSymbol);
    void pushToFringe(vector<Symbol> symbols);
    Symbol popFromFringe();
    bool isHeadOnly(Symbol aHead);
    bool fail(Symbol aSymbol);
    void test();
};

#endif // BACKWARDCHAIN_H
