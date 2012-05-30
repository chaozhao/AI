#ifndef Clause_H
#define Clause_H

#include "symbol.h"
#include <vector>

class Clause
{
private:
    vector<Symbol> body;
    Symbol head;
public:
    Clause();
    ~Clause();

    void setHead(Symbol aHeadSymbol);
    void addBody(Symbol aSymbol);
    void setBody(vector<Symbol> symbols);
    vector<Symbol> getBody();
    Symbol getBody(unsigned n);
    Symbol getHead();
};

#endif // Clause_H
