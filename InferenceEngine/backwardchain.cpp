#include "backwardchain.h"

BackwardChain::BackwardChain(KnowledgeBase *_kb)
{
    this->kb = _kb;
}
bool BackwardChain::solve()
{
    bool successful = false;

    for(unsigned i = 0;i<kb->getClause().size();i++ )
    {
        if( kb->getClause(i).getHead() == kb->getQuery())
        {
            successful = true;
            break;
        }
    }

    if(successful)
    {
        Symbol subGoal;
        pushToFringe(kb->getQuery());
         while(fringe.size() > 0 && successful)
        {
            subGoal = popFromFringe();
            subGoal = findSubgoal(subGoal);
            successful = fail(subGoal);
            pushToFringe(subGoal);
        };

         if(successful)
         {
             printSolution();
         }
         else
         {

         }
    }
    return successful;
}
void BackwardChain::printSolution()
{

}

Symbol BackwardChain::findSubgoal(Symbol head)
{
    Symbol goal;

    for(unsigned i = 0;i<kb->getClause().size();i++ )
    {
        if( kb->getClause(i).getHead() == head)
        {
            if(kb->getClause(i).getBody().size() <= 0)
            {
                return head;
            }
            else if(kb->getClause(i).getBody().size() > 0)
            {
                goal = kb->getClause(i).getBody(0);
                //cout<<goal.getName()<<"=>"<< head.getName() <<endl;
                return goal;
            }
        }
    }
    return head;
}

vector<Symbol> BackwardChain::findSubgoals(Symbol aSymbol)
{
    vector<Symbol> symbols;

    for(unsigned i = 0;i<kb->getClause().size();i++ )
    {
        if(kb->getClause(i).getHead() == aSymbol)
        {
            for(unsigned j=0;j<kb->getClause().size();j++)
            {
                symbols.push_back(kb->getClause(i).getBody(j));
            }
        }
    }
    return symbols;
}

void BackwardChain::pushToFringe(vector<Symbol> symbols)
{
    //TODO
    for(unsigned x=0;x<symbols.size();x++)
    {
        for(unsigned i = 0;i<kb->getClause().size();i++ )
        {
            if(kb->getClause(i).getHead() == symbols[x])
            {
                if(!isHeadOnly(symbols[x]))
                {
                    fringe.push(symbols[x]);
                    // cout<<"push:"<<aSymbol.getName()<<endl;
                }
                else
                {
                    cout<<symbols[x].getName()<<" ";
                }

            }
        }
    }
}

void BackwardChain::pushToFringe(Symbol aSymbol)
{
    for(unsigned i = 0;i<kb->getClause().size();i++ )
    {
        if(kb->getClause(i).getHead() == aSymbol)
        {
            if(!isHeadOnly(aSymbol))
            {
                fringe.push(aSymbol);
                // cout<<"push:"<<aSymbol.getName()<<endl;
             }
            else
            {
                cout<<aSymbol.getName()<<" ";
            }

        }
    }
}

Symbol BackwardChain::popFromFringe()
{
    if(fringe.size()>0)
    {
        Symbol top = fringe.top();
        fringe.pop();
        cout<<top.getName()<<" ";
        return top;
    }
}

bool BackwardChain::isHeadOnly(Symbol aHead)
{
    for(unsigned i = 0;i<kb->getClause().size();i++ )
    {
        if(kb->getClause(i).getHead() == aHead)
        {
            if(kb->getClause(i).getBody().size() == 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool BackwardChain::fail(Symbol aSymbol)
{
    for(unsigned i = 0;i<kb->getClause().size();i++ )
    {
        if(kb->getClause(i).getHead() == aSymbol)
        {
                return true;
        }
    }
    return false;
}

void BackwardChain::test()
{
    kb->test();
}

