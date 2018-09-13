//#define CATCH_CONFIG_MAIN
#include "Catch.hpp"
#include "avltree.h"
#include "hashtable.h"
#include "question.h"
#include "hashindex.h"
#include "avlindex.h"
#include "indexinterface.h"
#include <iostream>
#include <string>

//TEST_CASE("AVLTree Class Polymorphism", "AVLTree")
//{
//    question* quest = new question();
//    quest->setTitle("title");
//    quest->setQuestion("question");
//    quest->setCode("Code");
//    quest->setDate("Date");
//    quest->setQId("qId");
//    quest->setScore("Score");
//    quest->setUserId("userId");

//    question* quest2 = new question();
//    quest2->setTitle("ntitle");
//    quest2->setQuestion("nquestion");
//    quest2->setCode("nCode");
//    quest2->setDate("nDate");
//    quest2->setQId("nqId");
//    quest2->setScore("nScore");
//    quest2->setUserId("nuserId");

//    string str = "hi";
//    indexInterface* one = new avlIndex();
//    SECTION("Insert Method")
//    {
//        one->insert(str, quest);
//        str = "yo";
//        one->insert(str, quest);
//        str = "sup";
//        one->insert(str, quest);
//        str = "wussguud";
//        one->insert(str, quest);
//        str = "oy";
//        one->insert(str, quest);
//        str = "quvo";
//        one->insert(str, quest);
//        str = "bueno";
//        one->insert(str, quest);
//        str = "sah";
//        one->insert(str, quest);
//        str = "sah";
//        one->insert(str, quest2);

//        vector<question*> idx = one->search("sah");
//        cout << "size: " << idx.size() << endl;
//        REQUIRE(!one->isEmpty());
//        cout << "In Order: " << endl;
//        one->display();
//    }
//}

TEST_CASE("hashTable Class Polymorphism", "hashTable")
{
    question* quest = new question();
    quest->setTitle("title");
    quest->setQuestion("question");
    quest->setCode("Code");
    quest->setDate("Date");
    quest->setQId("qId");
    quest->setScore("Score");
    quest->setUserId("userId");

    question* quest2 = new question();
    quest2->setTitle("ntitle");
    quest2->setQuestion("nquestion");
    quest2->setCode("nCode");
    quest2->setDate("nDate");
    quest2->setQId("nqId");
    quest2->setScore("nScore");
    quest2->setUserId("nuserId");



    indexInterface* one = new hashIndex();
    SECTION("Insert Method")
    {
        string str = "hi";
        one->insert(str, quest);
        str = "yo";
        one->insert(str, quest);
        str = "sup";
        one->insert(str, quest);
        str = "wussguud";
        one->insert(str, quest);
        str = "oy";
        one->insert(str, quest);
        str = "quvo";
        one->insert(str, quest);
        str = "bueno";
        one->insert(str, quest);
        str = "sah";
        one->insert(str, quest);
        one->insert(str, quest2);
        one->insert(str, quest);
        one->insert(str, quest2);

        //vector<question*> idx = one->search("sah");
        //cout << "vector size: " << idx.size() << endl;

//        for(int i = 0; i < idx.size(); i++){
//            cout << *idx[i] << endl;
//        }
        //REQUIRE(!one->isEmpty());
        //REQUIRE(one->search("sah").size() == 3);
        cout << "Display:" << endl;
        one->display();

        delete one;
    }
}
