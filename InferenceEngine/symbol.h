#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <string>

using namespace std;

class Symbol
{
private:
    string name;
public:
    Symbol(string name);
    Symbol ();
    ~Symbol();
    string getName() const;
    void setName(string name);
    bool operator==(const Symbol that);
    bool operator!=(const Symbol that);
};

#endif // SYMBOL_H
