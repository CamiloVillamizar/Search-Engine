#ifndef SEARCHQUERY_H
#define SEARCHQUERY_H
#include "question.h"
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

class searchQuery
{
    private:
        string path;
        vector<question*>::iterator itrs;
        void openOutside(string);
    public:
        searchQuery();
        void askUser();
        vector<question*> unionize(vector<question*>&, vector<question*>&);
        vector<question*> differentiate(vector<question*>&, vector<question*>&);
        vector<question*> intersect(vector<question*>&, vector<question*>&);
};

#endif // SEARCHQUERY_H
