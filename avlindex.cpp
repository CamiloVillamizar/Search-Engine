#include "avlindex.h"
#include "avltree.h"
#include "index.h"
#include <iostream>
using namespace std;

avlIndex::avlIndex()
{
    tree = new AVLTree<index1>;
    wordCount = 0;
    questionCount = 0;
}

void avlIndex::insert(string& arg, question*& quest){
    index1 idx;
    idx.setWord(arg);
    idx.pushback(quest);
    tree->insert(idx);
}

vector<question*> avlIndex::search(string arg){
    return tree->search(arg).getVect();
}

bool avlIndex::isEmpty(){
    return tree->isEmpty();
}

void avlIndex::display(){
    tree->printInOrder();
}

void avlIndex::display(ofstream& out)
{
    tree->printIndex(out);
}

void avlIndex::bringBack(ifstream & str)
{
    tree->bringBack(str);
}
