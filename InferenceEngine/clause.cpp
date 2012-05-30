#include "clause.h"

Clause::Clause()
{

}

Clause::~Clause()
{

}

void Clause::setHead(Symbol aHead)
{
    head =aHead;
}

void Clause::addBody(Symbol aSymbol)
{
    body.push_back(aSymbol);
}

void Clause::setBody(vector<Symbol> symbols)
{

}

Symbol Clause::getBody(unsigned n)
{
    return body[n];
}

vector<Symbol> Clause::getBody()
{
    return body;
}

Symbol Clause::getHead()
{
    return head;
}
