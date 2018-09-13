#ifndef INDEX_H
#define INDEX_H
#include <string>
#include <vector>
#include "question.h"

using namespace std;

class index1
{
private:
    string word;
    vector<question*> vect;
public:
    index1();
    index1(string);
    index1& operator=(const index1);
    void setWord(string);
    void setVect(vector<question*>);
    question* getPtr();
    void pushback(question*);
    string getWord() const;
    vector<question*> getVect() const;
    bool operator <(index1);
    bool operator >(index1);
    bool operator ==(index1);
    bool operator !=(index1);
    friend ostream& operator <<(ostream&, const index1);
};

#endif // INDEX_H
