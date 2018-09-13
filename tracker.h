#ifndef TRACKER_H
#define TRACKER_H
#include <string>
#include <iostream>
#include "question.h"
using namespace std;

class tracker
{
private:
    int wordCount;
    int questCount;
public:
    tracker();
    void incWords();
    void setQuest(int);
    int getQuest();
    int getWords();
};
#endif // TRACKER_H
