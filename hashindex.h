#ifndef HASHINDEX_H
#define HASHINDEX_H
#include "indexinterface.h"
#include "index.h"
#include "hashtable.h"
//#include "question.h"


class hashIndex : public indexInterface
{
private:
    hashTable<string, question*> table;
    int capacity;
public:
    hashIndex();
    virtual void insert(string&, question*&);
    virtual vector<question*> search(string);
    virtual bool isEmpty();
    virtual void display();
protected:
    virtual void display(ofstream&);
    virtual void bringBack(ifstream&);
};

#endif // HASHINDEX_H
