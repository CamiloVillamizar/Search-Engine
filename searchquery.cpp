#include "searchquery.h"

searchQuery::searchQuery()
{
}

void searchQuery::askUser()
{
    cout << "Enter the path you want "
         << "to open outside the directory."
         << endl;
    cin >> path;
    openOutside(path);
}

void searchQuery::openOutside(string file)
{
    ifstream infile;
    infile.open(file);
    if(!infile)
    {
        cout << "Failed to open file." << endl;
        exit(EXIT_FAILURE);
    }
}

vector<question*> searchQuery::unionize(vector<question*> &first, vector<question*>& second)//OR
{
    vector<question*> unionVect;
    vector<question*>::iterator firstIt = unique(first.begin(), first.end());
    first.resize(distance(first.begin(), firstIt));

    vector<question*>::iterator secondIt = unique(second.begin(), second.end());
    second.resize(distance(second.begin(), secondIt));

    unionVect.resize(first.size()+second.size());
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    itrs=set_union(first.begin(), first.end(), second.begin(), second.end(), unionVect.begin());
    unionVect.resize(itrs-unionVect.begin());

//    cout << "--------------" << endl;
//    cout << "size: " << unionVect.size() << endl;
//    for(int i = 0; i < unionVect.size(); i++)
//    {
//        cout << unionVect[i] << endl;
//    }
    return unionVect;
}

vector<question*> searchQuery::differentiate(vector<question*>& first, vector<question*>& second)//NOT
{
    vector<question*> unionVect;
    vector<question*>::iterator firstIt = unique(first.begin(), first.end());
    first.resize(distance(first.begin(), firstIt));

    vector<question*>::iterator secondIt = unique(second.begin(), second.end());
    second.resize(distance(second.begin(), secondIt));

    unionVect.resize(first.size()+second.size());
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    itrs=set_difference(first.begin(), first.end(), second.begin(), second.end(), unionVect.begin());
    unionVect.resize(itrs-unionVect.begin());

//    cout << "--------------" << endl;
//    cout << "size: " << unionVect.size() << endl;
//    for(int i = 0; i < unionVect.size(); i++)
//    {
//        cout << unionVect[i] << endl;
//    }
    return unionVect;
}

vector<question*> searchQuery::intersect(vector<question*>& first, vector<question*>& second)//AND
{
    vector<question*> unionVect;
    vector<question*>::iterator firstIt = unique(first.begin(), first.end());
    first.resize(distance(first.begin(), firstIt));

    vector<question*>::iterator secondIt = unique(second.begin(), second.end());
    second.resize(distance(second.begin(), secondIt));

    unionVect.resize(first.size()+second.size());
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    itrs=set_intersection(first.begin(), first.end(), second.begin(), second.end(), unionVect.begin());
    unionVect.resize(itrs-unionVect.begin());

//    cout << "--------------" << endl;
//    cout << "size: " << unionVect.size() << endl;
//    for(int i = 0; i < unionVect.size(); i++)
//    {
//        cout << unionVect[i] << endl;
//    }
    return unionVect;
}


