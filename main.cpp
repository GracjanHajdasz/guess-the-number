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
        if (!playing)
        {
            string again;
            cout << "czy chcesz zagrac ponownie? (t/n): ";
            cin >> again;
            if (again == "n" || again == "N")
                break;
            else if (again == "t" || again == "T")
            {
                continue;
            }
            else
            {
                cout << "nieprawidlowa odpowiedz, konczenie gry." << endl;
                break;
            }
        }
    }
    return 0;
}