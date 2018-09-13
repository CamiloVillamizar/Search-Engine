#include "tracker.h"

tracker::tracker()
{
    wordCount = 0;
}

void tracker::incWords()
{
    wordCount++;
}

void tracker::setQuest(int num)
{
    questCount = num;
}

int tracker::getQuest()
{
    return questCount;
}

int tracker::getWords()
{
    return wordCount;
}
