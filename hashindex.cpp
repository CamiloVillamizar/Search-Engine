#include "hashindex.h"
#include "index.h"

hashIndex::hashIndex()
{

}

void hashIndex::insert(string& arg, question*& quest){
    table.insert(arg, quest);
}

vector<question*> hashIndex::search(string arg){
   //return table.search(arg);
}

bool hashIndex::isEmpty(){
    if(table.getSize() == 0)
        return true;
    return false;
}

void hashIndex::display(){
    table.display();
}


void hashIndex::display(ofstream & out)
{
    table.display(out);
}

void hashIndex::bringBack(ifstream & str)
{
    table.bringBack(str);
}
