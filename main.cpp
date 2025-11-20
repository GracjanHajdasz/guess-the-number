#include <iostream>
#include "functions.hpp"

using namespace std;

bool guessed = false;
int numberToGuess;
bool playing = false;

// scoreboard
string username;
string level;
string userTrials;
vector<string> usernames;
vector<string> levels;
vector<int> trials;

int main()
{

    while (true)
    {

        if (!playing)
            welcome();
        else
            gameplay();
        guessed = false;
    }

    system("pause");
    return 0;
}