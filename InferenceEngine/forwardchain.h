#ifndef FORWARDCHAIN_H
#define FORWARDCHAIN_H
#include "knowledgebase.h"

class ForwardChain
{
private:
    KnowledgeBase *kb;
public:
    ForwardChain();
    ForwardChain(KnowledgeBase *kb);
    bool solve();
    void test();
};

#endif // FORWARDCHAIN_H
