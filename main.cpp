#include <iostream>
#include "functions.hpp"

using namespace std;

int numberToGuess;
int bet;

bool guessed = false;
bool playing = false;
bool isBetMode = false;

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

    return 0;
}