#ifndef KNOWLEDGEBASE_H
#define KNOWLEDGEBASE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "symbol.h"
#include "Clause.h"

using namespace std;

class KnowledgeBase
{
private:
    vector<Clause> Clauses;
    Symbol query;
public:
        KnowledgeBase();
        KnowledgeBase(char* filename);
        ~KnowledgeBase();
        string readFile(char* filename);
        string trim(string& aString);
        void addAClause(Clause aClause);
        void addAllClause(string input);
        Clause getClause(unsigned index)const;
        vector<Clause> getClause()const;
        //vector<Clause> getAllClause()const;
        vector<string> splitString(string aString,string separator);
        Symbol getQuery()const;
        void setQuery(Symbol query);
        void test();
};

#endif // KNOWLEDGEBASE_H
