#include "question.h"
#include "porter2_stemmer.h"
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>

question::question()
{
    qId = "";
    userId = "";
    date = "";
    score = "";
    title = "";
    quest = "";
    code = "";
    queryNum = 0;
}

question::question(string qid, string uid, string d, string scr, string ttl, string qst, string cd, int qNum){
    qId = qid;
    userId = uid;
    date = d;
    score = scr;
    title = ttl;
    quest = qst;
    code = cd;
    queryNum = qNum;
}

void question::setQId(string arg){
    qId = arg;
}

string question::getQId() const{
    return qId;
}

string question::getUserId() const{
    return userId;
}

void question::setUserId(string arg){
    userId = arg;
}

string question::getDate() const{
    return date;
}

void question::setScore(string arg){
    score = arg;
}

string question::getScore() const{
    return score;
}

void question::setDate(string arg){
    date = arg;
}

string question::getTitle() const{
    return title;
}

string question::getSTitle() const{
    string str = this->getTitle();
    string temp;
    if(str.length() < 40)
        temp = str;
    else{
        for(int i = 0; i < 40; i++){
            temp += str.at(i);
        }
    }
    return temp += "...";
}

void question::setTitle(string arg){
    title = arg;
}

string question::getQuestion() const{
    return quest;
}

void question::setQuestion(string arg){
    quest = arg;
}


string question::getCode() const{
    return code;
}

void question::setCode(string arg){
    code = arg;
}

void question::incQNum(){
    queryNum++;
}

int question::getQNum(){
    return queryNum;
}

void question::clear(){
    qId = "";
    userId = "";
    date = "";
    score = "";
    title = "";
    quest = "";
    code = "";
}

void question::display()
{
    this->getQuestion();
}

bool question::operator ==(question*& rhs){
    return this->getQNum() == rhs->getQNum();
}

bool question::operator <(question& rhs){
    return this->getQNum() < rhs.getQNum();
}

bool question::operator >(question& rhs){
    return this->getQNum() > rhs.getQNum();
}

int question::operator -(question& rhs){
    return this->getQNum() - rhs.getQNum();
}

void question::printToScreen(){
    cout << "=====================================================" << endl;
    cout << "\033[1;4mQuestion id:\033[0m" << endl;
    cout << "\t" << this->getQId() << endl;
    cout << "\033[1;4mUser ID:\033[0m" << endl;
    cout << "\t" << this->getUserId() << endl;
    cout << "\033[1;4mDate:\033[0m" << endl;
    cout << "\t" << this->getDate() << endl;
    cout << "\033[1;4mScore:\033[0m" << endl;
    cout << "\t" << this->getScore() << endl;
    cout << "\033[1;4mTitle:\033[0m" << endl;
    cout << "\t" << this->getTitle() << endl;
    cout << "\033[1;4mQuestion:\033[0m" << endl;
    cout << "\t" << this->getQuestion() << endl;
    if(this->getCode() != ""){
        cout << "\033[1;4mCode:\033[0m" << endl;
        cout << "\t" << this->getCode() << endl;
    } else {
        cout << "\033[1;4mNo code to show\033[0m" << endl;
    }
    cout << "=====================================================" << endl;
}

ostream& operator <<(ostream& out, const question& quest){
    out << quest.getQId() << "|" << endl;
    out << quest.getUserId() << "|" << endl;
    out << quest.getDate() << "|" << endl;
    out << quest.getScore() << "|" << endl;
    out << quest.getTitle() << "|" << endl;
    out << quest.getQuestion() << "|" << endl;
    if(quest.getCode() != ""){
        out << "!CODE!" << quest.getCode() << "|" << endl;
    }
    return out;
}

question::~question(){
    delete this;
}
