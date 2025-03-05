#include <fstream>
#include <thread>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    fstream file("test.txt");
    if (!file)
    {
        cerr << "Whoaa, could not open the file\n";
        return 1;
    }
    for (int i = 0; i < 1000; i++)
    {
        this_thread::sleep_for(1s);
        file << "abacaba# " << i << '\n' << flush;
    }

    return 0;
}