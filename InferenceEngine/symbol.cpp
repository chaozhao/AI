#include "symbol.h"

Symbol::Symbol()
{

}

Symbol::Symbol(string aName)
{
    name = aName;
}

Symbol::~Symbol()
{

}

string Symbol::getName() const
{
    return name;
}

void Symbol::setName(string aName)
{
    name = aName;
}

bool Symbol::operator==(const Symbol that)
{
    if (name.compare(that.getName())==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

