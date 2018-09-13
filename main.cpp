#define CATCH_CONFIG_RUNNER
#include "Catch.hpp"
#include "avltree.h"
#include "hashtable.h"
#include "question.h"
#include "hashindex.h"
#include "avlindex.h"
#include "indexinterface.h"
#include "porter2_stemmer.h"
#include "searchquery.h"
#include "reader.h"
#include <ctime>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <functional>
#include <algorithm>
#include "math.h"

#define TEST true

using namespace std;

int main( int argc, char* argv[])
{
    if (argc > 1 && strcmp(argv[1], "-t") == 0)
    {
        if(TEST)
        {
            return Catch::Session().run();
        }
    }//Run test.cpp
    else
    {

        Reader one;

        vector<string>* paths;

        one.start(paths);

        int start_s=clock();
        indexInterface* handler = one.parser();

        bool overMinute = false;

        int stop_s=clock();
        double seconds = (stop_s-start_s)/double(CLOCKS_PER_SEC);

        int minutes = floor (seconds/60);
        seconds = -1*(minutes*60 - seconds);

        if(floor (seconds/60) > 0){
            cout << " " << endl;
            cout << "Finished parsing data in ";
            if(seconds < 10)
                cout << minutes << ":0" << seconds;
            else
                cout << minutes << ":" << seconds;

            cout << " minutes." << endl;
        } else {
            cout << "Finished parsing data in " << seconds << " seconds." << endl;
        }





        one.runSearch(handler);


//        ofstream outFile;
//        outFile.open("PersistantIndex.txt");
//        outFile << handler;


        cout << "End Program" << endl;
    }
    return 0;
}
