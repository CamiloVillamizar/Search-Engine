#ifndef MAPINDEX_H
#define MAPINDEX_H
#include "indexinterface.h"
#include "hashmap.h"
#include "index.h"


class mapIndex : public indexInterface
{
private:
    hashMap<string, index1> map;
    int size;
    int capacity;
public:
    mapIndex();
    int getSize();
    int getCap();
    virtual void insert(string&, question*&);
    virtual vector<question*> search(string);
    virtual bool isEmpty();
    virtual void display();
protected:
    virtual void display(ofstream&);
    virtual void bringBack(ifstream&);
    //virtual void PrintIndex();
};

#endif // MAPINDEX_H
