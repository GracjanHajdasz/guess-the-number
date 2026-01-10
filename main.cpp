#include <iostream>
#include "functions.hpp"
#include "ui.hpp"

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
    string choice;

    while (true)
    {
        UI::clear();
        UI::header("GUESS THE NUMBER");
        UI::menu();
        cin >> choice;

        if (choice == "1")
        {
            UI::clear();
            UI::header("START GRY");
            welcome(); // Twoja funkcja welcome()
            if (playing)
                gameplay(); // Twoja funkcja gameplay()
            guessed = false;
        }
        else if (choice == "2")
        {
            UI::clear();
            UI::header("TABLICA WYNIKOW");
            readFile(); // wczytaj aktualne wyniki
            viewScoreboard();
            UI::pause();
        }
        else if (choice == "0")
        {
            UI::info("Do zobaczenia!");
            break;
        }
        else
        {
            UI::error("Nieprawidlowy wybor!");
            UI::pause();
        }
    }

    return 0;
}
