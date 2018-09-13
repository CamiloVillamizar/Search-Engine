#ifndef READER_H
#define READER_H
#include "avltree.h"
#include "hashtable.h"
#include "question.h"
#include "hashindex.h"
#include "avlindex.h"
#include "indexinterface.h"
#include "porter2_stemmer.h"
#include "mapindex.h"
#include "searchquery.h"
#include "tracker.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <functional>
#include <algorithm>


class Reader
{
private:
    tracker one;
public:
    Reader();
    indexInterface* parser();
    void runSearch(indexInterface*&);
    vector<string> getQuery();
    string fixQuest(string&, vector<string>&, indexInterface*&, question*&);
    vector<question*> sortVector(vector<question*>&, string);
    void displayResults(vector<question*>&, indexInterface*&);
    void quickSort(vector<question*>&, int, int);
    int compare (const void *, const void *);
    void writeTo(ofstream&, indexInterface*&);
    void basicStats();
    void askResults();
    void start(vector<string>*&);
};

#endif // READER_H
