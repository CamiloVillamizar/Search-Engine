#include "mapindex.h"
#include "index.h"

mapIndex::mapIndex()
{
}

void mapIndex::insert(string& arg, question*& quest){
    index1 idx;
    idx.setWord(arg);
    idx.pushback(quest);
    map.insert(arg, idx);
}

vector<question*> mapIndex::search(string arg){
    return map.search(arg).getVect();
}

bool mapIndex::isEmpty(){
    if(map.getSize() == 0)
        return true;
    return false;
}

void mapIndex::display(){
    map.display();
}

int mapIndex::getSize()
{
    return size;
}

int mapIndex::getCap()
{
    return capacity;
}

void mapIndex::display(ofstream& out)
{
    map.display(out);
}

void mapIndex::bringBack(ifstream & str)
{
    map.bringBack(str);
}
