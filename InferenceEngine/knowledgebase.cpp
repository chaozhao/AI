#include "KnowledgeBase.h"
using namespace std;

KnowledgeBase::KnowledgeBase()
{

}

KnowledgeBase::KnowledgeBase(char* filename)
{
    string sentence = readFile(filename);
    addAllClause(sentence);
}

KnowledgeBase::~KnowledgeBase()
{

}

string KnowledgeBase::readFile(char* filename)
{
    string stringmodels;
    ifstream inputFile;
    inputFile.open(filename);
    vector<string> stringVector;
    if (inputFile)
    {        
        for( std::string line; getline( inputFile, line ); )
        {
            stringVector.push_back(line);
        }
        stringmodels = stringVector[1];
        stringmodels = trim(stringmodels);
        Symbol theQuery(stringVector[3]);
        setQuery(theQuery);
        inputFile.close();
    }
    else
    {
        std::cout << "Can't open " << filename << " for reading...\n";
    }


    return stringmodels;
}


void KnowledgeBase::addAClause(Clause aClause)
{
    Clauses.push_back(aClause);
}

void KnowledgeBase::addAllClause(string input)
{
    vector<string> stringClauses = splitString(input,";");
    for(unsigned i = 0; i<stringClauses.size(); i++)
    {
        Clause aClause;
        vector<string> symbols = splitString(stringClauses[i],"=>");

        if(symbols.size()>1)
        {
            //do something with body
            string stringbody = symbols[0];

            vector<string> bodySymbols = splitString(stringbody,"&");

            for(unsigned i=0; i<bodySymbols.size(); i++)
            {
                Symbol aSymbol(bodySymbols[i]);
                aClause.addBody(aSymbol);
            }
            //do something with head
            string stringhead = symbols[1];

            Symbol headSymbol(stringhead);
            aClause.setHead(headSymbol);


        }
        else if(symbols.size()==1) // there is only one head
        {
            string stringhead = symbols[0];
            Symbol headSymbol(stringhead);
            aClause.setHead(headSymbol);
        }


        //vector<string> symbolsofbody = splitString(stringbody,"&");

        addAClause(aClause);
    }

}

Clause KnowledgeBase::getClause(unsigned index) const
{
    return Clauses[index];
}

vector<Clause> KnowledgeBase::getClause()const
{
    return Clauses;
}

vector<string> KnowledgeBase::splitString(string input,string separator)
{
    vector<string> results;
    unsigned found;
    found = input.find_first_of(separator);
    while(found != string::npos)
    {
        if(found > 0)
        {
            results.push_back(input.substr(0,found));
        }
        input = input.substr(found+1);
        found = input.find_first_of(separator);
    }

    if(input.length() > 0)
    {
        results.push_back(input);
    }
    return results;
}

string KnowledgeBase::trim(string& aString)
{
    size_t found;
    found=aString.find_first_of(" ");
    while (found!=string::npos && found<aString.size())
    {
        aString.erase(found,1);
        found=aString.find_first_of(" ",found+1);
    }
    return aString;
}

Symbol KnowledgeBase::getQuery() const
{
    return query;
}

void KnowledgeBase::setQuery(Symbol query)
{
    this->query = query;
}

void  KnowledgeBase::test()
{
    for(unsigned i = 0; i<Clauses.size();i++)
    {
        if(Clauses[i].getBody().size() > 0)
        {
            for(unsigned j=0;j<Clauses[i].getBody().size();j++)
            {
                cout<<Clauses[i].getBody(j).getName()<<"  ";
            }
            cout<<" => "<<Clauses[i].getHead().getName()<<endl;
        }
        else
        {
             cout<<"head: "<<Clauses[i].getHead().getName()<<endl;
        }
    }
    cout<<"\nQuery is: "<< query.getName()<<endl;
}
