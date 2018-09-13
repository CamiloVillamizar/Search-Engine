#ifndef INDEXINTERFACE_H
#define INDEXINTERFACE_H
#include "index.h"
#include "question.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class indexInterface
{
private:

public:
    indexInterface();
    virtual void insert(string&, question*&) = 0;
    virtual vector<question*> search(string) = 0;
    virtual bool isEmpty() = 0;
    virtual void display() = 0;
    friend ofstream& operator<<(ofstream& str, indexInterface*& II){
        cout << "in display" << endl;
        II->display(str);
        return str;
    }
    friend ifstream& operator>>(ifstream& str, indexInterface*& third)
    {
        third->bringBack(str);
        return str;
    }

protected:
    virtual void bringBack(ifstream&) = 0;
    virtual void display(ofstream&) = 0;

};

#endif // INDEXINTERFACE_H
