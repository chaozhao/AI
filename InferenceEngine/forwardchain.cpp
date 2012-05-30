#include "forwardchain.h"

ForwardChain::ForwardChain()
{

}

ForwardChain::ForwardChain(KnowledgeBase *_kb)
{
    this->kb = _kb;
}

bool ForwardChain::solve()
{
    bool answer = false;
    for(unsigned i = 0;i<kb->getClause().size();i++ )
    {
        if( kb->getClause(i).getHead() == kb->getQuery())
        {
            answer = true;
            break;
        }
    }

    if(!answer)
    {
        for(unsigned i = 0;i<kb->getClause().size();i++ )
        {
           //TODO push all facts to collections
        }
    }





    return answer;
}

void ForwardChain::test()
{
    kb->test();
}
