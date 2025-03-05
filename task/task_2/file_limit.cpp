#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <string>
#include <memory>


using namespace std;


int fileNum = 0;
vector<shared_ptr<ofstream>> files;

void createFiles(const int amountOfFilesToCreate)
{
    int counter = 0;
    while(counter < amountOfFilesToCreate)
    {
        counter++;
        fileNum++;

        string name = "file_" + to_string(fileNum) + ".txt";
        shared_ptr<ofstream> filePtr = make_shared<ofstream>(name, ios::out);
        if (!(*filePtr))
        {
            cerr << "File: " << name << " - was not created\n";
            continue;
        }

        files.push_back(filePtr);
    }

}


int main() 
{
    
    for (int i = 1; i <= 100; ++i) 
    {
        this_thread::sleep_for(1s);
        createFiles(10000);
    }

    cout << "All 1000000 files created.\n";
    return 0;
}
