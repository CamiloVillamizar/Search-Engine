
#ifndef QUESTION_H
#define QUESTION_H
#include <string>
#include <vector>
#include <algorithm>
//#include "avltree.h"


using namespace std;

class question
{
private:
    string qId;//ID for each question
    string userId;
    string date;
    string score;
    string title;
    string quest;
    string code;
    int queryNum;

public:
    question();
    question(string, string, string, string, string, string, string, int);
    void setIndex(string);
    string getIndex() const;
    vector<string> getKeyWords();
    void setQId(string);
    string getQId() const;
    void setUserId(string);
    string getUserId() const;
    void setDate(string);
    string getDate() const;
    void setScore(string);
    string getScore() const;
    void setTitle(string);
    string getTitle() const;
    string getSTitle() const;
    //void setQuestion(string&);
    void setQuestion(string);
    string getQuestion() const;
    void setCode(string);
    string getCode() const;
    void incQNum();
    int getQNum();
    void clear();
    void display();
    bool operator ==(question*&);
    bool operator <(question&);
    bool operator >(question&);
    int operator -(question&);
    void printToScreen();
    friend ostream& operator<< (ostream&, const question&);
    ~question();
};

#endif // QUESTION_H

