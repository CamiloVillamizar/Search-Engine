#ifndef AVLINDEX_H
#define AVLINDEX_H
#include "indexinterface.h"
#include "avltree.h"
#include "index.h"

using namespace std;

class avlIndex : public indexInterface
{
private:
    AVLTree<index1>* tree;
    int wordCount;
    int questionCount;
public:
    avlIndex();
    virtual void insert(string&, question*&);
    virtual vector<question*> search(string);
    virtual bool isEmpty();
    virtual void display();
protected:
    virtual void display(ofstream &);
    virtual void bringBack(ifstream&);
    //virtual void printIndex();
};

#endif // AVLINDEX_H
