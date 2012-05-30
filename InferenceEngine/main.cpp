#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "KnowledgeBase.h"
#include "TruthTable.h"
#include "backwardchain.h"
#include "forwardchain.h"

using namespace std;

/**
 * Inference Engine main function
 */

int main ( int argc, char *argv[] )
{
    string hello;
    bool result;
    KnowledgeBase *kb;
    if(argc == 3)
    {


        if(strcmp(argv[1],"TT") == 0)
        {
            cout<<"Using TT with "<<argv[2]<<endl;
            kb = new KnowledgeBase(argv[2]);
            TruthTable *tt = new TruthTable(kb);
            kb->test();
        }
        else if(strcmp(argv[1],"BC") == 0)
        {
            cout<<"Using BC with "<<argv[2]<<endl;
            kb = new KnowledgeBase(argv[2]);
            BackwardChain *bc = new BackwardChain(kb);
            kb->test();
            result = bc->solve();
        }
        else if(strcmp(argv[1],"FC") == 0)
        {
            cout<<"Using FC with "<<argv[2]<<endl;
            kb = new KnowledgeBase(argv[2]);
            ForwardChain *fc = new ForwardChain(kb); 
            fc->solve();
        }
        else
        {
            cout<<"Invalid argv..."<<endl;
        }
        if(result)
            cout<<endl<< "TRUE" <<endl;
        else
            cout<<endl<< "FALSE" <<endl;
    }
    else
    {
        cout<<"Error: invalide number of args..."<<endl;
        cout<<"Usage: Exe_name Method_name Knowledge_Base "<<endl;
    }

    return 0;
}
