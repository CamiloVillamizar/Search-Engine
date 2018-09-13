#include "index.h"
#include <vector>

index1::index1()
{
    word = "";
    vect.clear();
}

index1::index1(string arg){
    word = arg;
    vect.clear();
}

void index1::setWord(string arg){
    word = arg;
}

void index1::setVect(vector<question*> arg){
    vect = arg;
}

index1& index1::operator=(const index1 second)
{
    word = second.word;
    vect = second.vect;
    return *this;
}

string index1::getWord() const{
    return word;
}

vector<question*> index1::getVect() const{
    return vect;
}

bool index1::operator <(index1 arg){
    return this->getWord() < arg.getWord();
}

bool index1::operator >(index1 arg){
    return this->getWord() > arg.getWord();
}

bool index1::operator ==(index1 arg){
    return this->getWord() == arg.getWord();
}

bool index1::operator !=(index1 arg){
    return !(this->getWord() == arg.getWord());
}

ostream& operator <<(ostream& out, const index1 idx){
  //  out << idx.getWord() << "\t";
   // out << "size: " <<
    for(int i = 0; i < idx.getVect().size(); i++)
    {
        out << *idx.getVect().at(i);
    }
    //out << idx.getVect().size();
    return out;
}

void index1::pushback(question* quest)
{
    vect.push_back(quest);
}

question* index1::getPtr(){
    return vect[0];
}
