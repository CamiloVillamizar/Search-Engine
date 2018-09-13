#include "reader.h"
#include "sstream"
#include "searchquery.h"
#include <iterator>

Reader::Reader()
{

}

indexInterface* Reader::parser()
{
    int questionCount = 0;
    vector<string> fileNames;

    ifstream pathNames;
    pathNames.open("PathsFile.txt");

    string input;

    if(pathNames){
        while(!pathNames.eof()){
            pathNames >> input;
            fileNames.push_back(input);
        }
    }

    fileNames.push_back("2008-questions.psv");
    fileNames.push_back("2009-questions.psv");
//    fileNames.push_back("2010-questions.psv");
//    fileNames.push_back("2011-questions.psv");
//    fileNames.push_back("2012-questions.psv");
//    fileNames.push_back("2013-questions.psv");
//    fileNames.push_back("2014-questions.psv");
//    fileNames.push_back("2015-questions.psv");
//    fileNames.push_back("2016-questions.psv");


    int answer = 0;
    cout << "Run with AVLTree(1), hashtable(2) or hashmap(3)?" << endl;
    cin >> answer;
    while(!(answer == 1 || answer == 2 || answer == 3)){
        cout << "\033[1;31mInvalid Input\033[0m\n" << endl;
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << "Run with AVLTree(1), hashtable(2) or hashmap(3)?" << endl;
        cin >> answer;
    }

    int start_s=clock();

    indexInterface* handler;
    if(answer == 1){
        handler = new avlIndex();
        cout << "Running program with AVL Tree" << endl;
    }
    else if(answer == 2){
        handler = new hashIndex();
        cout << "Running program with Hash Table" << endl;
    }else if(answer == 3){
        handler = new mapIndex();
        cout << "Running program with Hash Map" << endl;
    }


    vector<string> stopWord;
    ifstream stopData{"stopWords.txt", ios::in};//Open file
    if(!stopData)
    {
        cout << "Stop Word file not found." << endl;
        exit(EXIT_FAILURE);
    }

    string word;
    for(int i = 0; i < 635; i++)//load all the stop words into the stopData vector
    {
        stopData >> word;
        stopWord.push_back(word);
    }

    question* current = new question();//keeps all the information for the current question object

    ifstream qFile08;

    cout << "Number of files being loaded: " << fileNames.size() << endl;

    for(int FileNum = 0; FileNum < fileNames.size(); FileNum++){
        cout << "\033[1;34mFile: " << fileNames[FileNum] << "\033[0m" << endl;

        qFile08.open(fileNames[FileNum]);
        if(!qFile08)
        {
            cout << "\033[1;31mUnable to find: " << fileNames[FileNum] << "\033[0m" << endl;
            exit(EXIT_FAILURE);
        } else
            cout << "\033[1;32mFile opened\033[0m" << endl;

        string input;
        string temp;
        size_t index;
        qFile08 >> input;

        getline(qFile08, input, '|');


        while(!qFile08.eof())
        {
            current = new question();
            current->setQId(input);
            getline(qFile08, input, '|');

            current->setUserId(input);
            getline(qFile08, input, '|');

            current->setDate(input);
            getline(qFile08, input, '|');

            current->setScore(input);
            getline(qFile08, input, '|');

            index = input.find("<>?<>?<>");
            while(index > input.length())
            {
                getline(qFile08, temp, '|');
                input += '|' + temp;
                index = input.find("<>?<>?<>");
            }

            temp = input.substr(0, index - 2);
            current->setTitle(temp);//Passed by reference, but its making a copy to temp right before so is it faster?
            current->setTitle(input.substr(0, index - 2));

            input = input.substr(index + 8, input.length() - index);

            index = input.find("<>?<>?<>");
            while(index > input.length())
            {
                getline(qFile08, temp, '|');
                input += '|' + temp;
                index = input.find("<>?<>?<>");
            }
            temp = input.substr(0,index);
            string quest = fixQuest(temp, stopWord, handler, current);
            current->setQuestion(temp);
            one.incWords();

            questionCount++;
            input = input.substr(index, input.length());
            getline(qFile08, input, '|');
            index = input.find("<>!<>!<><>!<>!<>");
            if(index == 0)
            {
                current->setCode("");
            }
            else
            {
                index = input.find("<>!<>!<>");
                input = input.substr(index + 8, input.length());
                index = input.find("<>!<>!<>");
                while(index > input.length())
                {
                    getline(qFile08, temp, '|');
                    input += temp;
                    index = input.find("<>!<>!<>");
                }
                temp = input.substr(0, index);
                current->setCode(temp);
                input = input.substr(index + 8, input.length());
            }
            index = input.find('\n');
            input = input.substr(index + 1, input.length());
            handler->insert(quest, current);
        }
        qFile08.close();
        qFile08.clear();
        cout << "\033[1;32mFile Closed\033[0m" << endl;
    }
    //cout << questionCount << " questions added to the tree" << endl;
    one.setQuest(questionCount);
    return handler;
}

void Reader::runSearch(indexInterface*& handler)
{
    searchQuery SQ;
    //vector<vector<question*>> vectors;

    int start_s=clock();

    vector<string> query = getQuery();

    vector<vector<question*>> AndOr;
    vector<vector<question*>> Not;
    bool andBool = true;
    bool notVect = false;

    if(query.size() == 1){
        vector<question*> tempVect = handler->search(query[0]);
        AndOr.push_back(sortVector(tempVect, query[0]));
    } else {

        for(int i = 0; i < query.size(); i++){
            if(query[i] == "AND")
                andBool = true;
            else if(query[i] == "OR")
                andBool = false;
            else if(query[i] == "NOT")
                notVect = true;

            else {
                if(notVect == true){
                    vector<question*> tempVect = handler->search(query[i]);
                    Not.push_back(sortVector(tempVect, query[i]));
                }
                else{
                    vector<question*> tempVect = handler->search(query[i]);
                    AndOr.push_back(sortVector(tempVect, query[i]));
                }
            }
        }
    }


    if(AndOr.size() == 0){
        cout << "\033[1;31mNO RESULTS FOUND\033[0m\n" << endl;
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        runSearch(handler);
        exit(0);
    }

    vector<question*> vect = AndOr[0];

    if(AndOr.size() > 1){
        if(andBool == true){
            for(int i = 1; i < AndOr.size(); i++){
                vect = SQ.intersect(vect, AndOr[i]);
            }
        } else {
            for(int i = 1; i < AndOr.size(); i++){
                vect = SQ.unionize(vect, AndOr[i]);
            }
        }
    }

    if(notVect == true){
        for(int i = 0; i < Not.size(); i++)
        vect = SQ.differentiate(vect, Not[i]);
    }
        int stop_s=clock();
        double seconds = (stop_s-start_s)/double(CLOCKS_PER_SEC);
        int minutes = floor (seconds/60);
        seconds = -1*(minutes*60 - seconds);


        if(floor (seconds/60) > 0){
            cout << " " << endl;
            cout << vect.size() << " results found in";
            if(seconds < 10)
                cout << minutes << ":0" << seconds;
            else
                cout << minutes << ":" << seconds;

            cout << " minutes." << endl;
        } else {
            cout << vect.size() << " results found in " << seconds << " seconds." << endl;
        }


        displayResults(vect, handler);

}

vector<string> Reader::getQuery(){
    string input;
    cout << "Enter you search now:" << endl;
    cin.ignore();
    getline(cin, input);

    istringstream iss(input);
    vector<string> query{istream_iterator<string>{iss}, istream_iterator<string>{}};


    for(int i = 0; i < query.size(); i++){
        if(!(query[i] == "NOT" || query[i] == "OR" || query[i] == "AND")){
            Porter2Stemmer::trim(query[i]);
            Porter2Stemmer::stem(query[i]);
        }
    }

    return query;
}

string Reader::fixQuest(string& arg, vector<string>& stops, indexInterface*& handler, question*& quest){
    string str;
    int index = 0;
    while(index < arg.length())
    {
        if(arg[index] == ' ')
        {
            string temp;
            int check;
               for(int i = 0; i < str.length(); i++){
                   check = str[i];
                   if(check > 32 && check < 176){
                       temp += str[i];
                   }
               }

               if(temp.length() < 8 && temp.length() > 2){

                   if(!binary_search(stops.begin(), stops.end(), temp)){
                       Porter2Stemmer::trim(temp);
                       Porter2Stemmer::stem(temp);
                       handler->insert(temp, quest);
                   }
               }
            str.clear();
            temp.clear();
        }
        else
            str+= arg[index];
        index++;
    }
    return str;
}

vector<question*> Reader::sortVector(vector<question*>& vect, string query){
    string str;
    for(int i = 0; i < vect.size(); i++){
        int index = 0;
        string qText = vect[i]->getQuestion();
        while(index < qText.length())
        {
            if(qText[index] == ' ')
            {
                string temp;
                int check;
                   for(int i = 0; i < str.length(); i++){
                       check = str[i];
                       if(check > 65 && check < 122){
                           temp += str[i];
                       }
                   }

                   Porter2Stemmer::trim(temp);
                   Porter2Stemmer::stem(temp);

                   if(temp == query){
                       vect[i]->incQNum();
                   }

                str.clear();
                temp.clear();
            }
            else
                str+= qText[index];
            index++;
        }
    }

    quickSort(vect, 0, vect.size()-1);

    reverse(vect.begin(), vect.end());

    vector<question*>::iterator it = unique(vect.begin(), vect.end());
    vect.resize(distance(vect.begin(), it));

    return vect;

}

void Reader::displayResults(vector<question*>& questVect, indexInterface*& handler){
    cout << "\033[1;34m+++++++++++++++++++++QUESTION RESULTS++++++++++++++++++\033[0m\n" << endl;

    int input;
    bool leaveDisplay = false;
    bool lastGroup = false;
    int min = 0;
    int max;

    if(questVect.size() >= 15)
        max = 15;
    else{
        max = questVect.size();
        lastGroup = true;
    }

    while(leaveDisplay == false){
        cout << "Showing results " << min << " - " << max << "; " << questVect.size() << " Results total" << endl;
        for(int i = min; i < max; i++){
            if(max == questVect.size()){
                min = max - 15;
                if(min < 0)
                    min = 0;
                lastGroup = true;
            }

            cout << "(" << "\033[4m" << i+1 << "\033[0m): " << questVect[i]->getSTitle() << endl;
        }
        if(lastGroup == false){
            cout << "Enter 0 to see the next 15 questions, -1 to search again, or -2 to exit the search" << endl;
            cin >> input;
            if((input >= min+1 && input <= max) && input != 0){
                questVect[input-1]->printToScreen();
            }
            else if(input == -1)
                runSearch(handler);
            else if(input == -2)
                leaveDisplay = true;
            else if(input == 0){
                cout << "input is 0" << endl;
                if(lastGroup == false){
                    if(questVect.size()-max > 15){
                        max += 15;
                        min += 15;

                    }
                    else{
                        min = max;
                        max = questVect.size();
                        lastGroup = true;
                    }
                } else {
                    cout << "\033[1;31mInvalid Input, try again\033[0m\n" << endl;
                    cout << '\a';
                    cout << '\a';
                    cout << '\a';
                    cout << '\a';
                    cout << '\a';
                    cout << '\a';
                    cout << '\a';
                    cout << '\a';
                    cout << '\a';
                    cout << '\a';
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            else{
                cout << "\033[1;31mInvalid Input, try again\033[0m\n" << endl;
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            for(int i = max; i > max-15; i--){
                if(i%15 == 0){
                    min = i;
                    break;
                }
            }
            cout << "This is the last group of questions, enter -1 to search again, or -2 to exit the search" << endl;
            cin >> input;
            if(input == -1){
                runSearch(handler);
                break;
            }
            else if(input == -2)
                    leaveDisplay = true;
            else if(input == 0){
                cout << "\033[1;31mInvalid Input, try again\033[0m\n" << endl;
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if(input >= min && input <= max){
                questVect[input + min - 1]->printToScreen();
            }
            else{
                cout << "\033[1;31mInvalid Input, try again\033[0m\n" << endl;
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cout << '\a';
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
}

void Reader::quickSort(vector<question*> &vec, int L, int R){
    int i, j, mid;
    i = L;
    j = R;
    mid = L + (R - L) / 2;
    question* piv = vec[mid];

    while (i<R || j>L) {
        while (*vec[i] < *piv)
            i++;
        while (*vec[j] > *piv)
            j--;

        if (i <= j) {
            swap(vec[i], vec[j]);
            i++;
            j--;
        }
        else {
            if (i < R)
                quickSort(vec, i, R);
            if (j > L)
                quickSort(vec, L, j);
            return;
        }
    }
}

void Reader::writeTo(ofstream& out, indexInterface*& handler)
{
    if(!out)
    {
        cout << "No persisting file to open." << endl;
        exit(EXIT_FAILURE);
    }
    cout << handler;
}

void Reader::basicStats()
{
    cout << "The total number of questions added. " << one.getQuest() << endl;
    cout << "The total number of words indexed. " << one.getWords() << endl;
    cout << "The top 50 most frequent words are. " << endl;
}

void Reader::askResults()
{
    int response;
    cout << "Enter 1 for statics." << endl;
    cin >> response;
    if(response == 1)
    {
        basicStats();
    }
    else
        cout << "Moving on." << endl;
}

void Reader::start(vector<string>*& paths)
{
    int response;
    string secRes;
    searchQuery one;
    cout << "Enter 1 for maintanence mode. Enter 2 for interactive mode." << endl;
    cin >> response;

    while(!(response == 1 || response == 2)){
        cout << "\033[1;31mInvalid Input\033[0m\n" << endl;
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << '\a';
        cout << "Enter 1 for maintanence mode. Enter 2 for interactive mode." << endl;
        cin >> response;
    }

    if(response == 1)
    {
        ofstream pathsFile;
        pathsFile.open("PathsFile.txt");

        while(true){
            cout << "Enter the path for your requested file. Enter 0 to finish" << endl;
            cin >> secRes;
            if(secRes == "0")
            {
                cout << "End program" << endl;
                exit(0);
            }
            pathsFile << secRes;
            pathsFile << endl;
        }
    }
}
