#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include "functions.hpp"
#include <cctype>
#include <fstream>

using namespace std;

void sortScoreboard()
{
    readFile();
    for (int i = 0; i < trials.size() - 1; i++)
    {
        for (int j = 0; j < trials.size() - i - 1; j++)
        {
            if (trials[j] > trials[j + 1])
            {
                swap(trials[j], trials[j + 1]);
                swap(usernames[j], usernames[j + 1]);
                swap(levels[j], levels[j + 1]);
            }
        }
    }

    // top 5
    if (trials.size() > 5)
    {
        trials.resize(5);
        usernames.resize(5);
        levels.resize(5);
    }
}

void viewScoreboard()
{

    if (trials.size() == 0)
        cout << "brak wynikow" << endl;
    else
    {
        cout << "tabalica wynikow:" << endl;
        sortScoreboard();
        for (int i = 0; i < usernames.size(); i++)
        {
            cout << usernames[i] << " | " << levels[i] << " | " << trials[i] << endl;
        }
        cout << "czy chcesz sortowac wyniki wedlug poziomu trudnosci? (t/n): ";
        string input;
        cin >> input;
        if (input == "t")
        {
            cout << "podaj poziom trudnosci (latwy/sredni/trudny): ";
            cin >> input;
            if (count(levels.begin(), levels.end(), input) == 0)
            {
                cout << "brak wynikow dla podanego poziomu trudnosci" << endl;
                return;
            }
            else
            {
                cout << "wyniki dla poziomu " << input << ":" << endl;
                for (int i = 0; i < usernames.size(); i++)
                {
                    if (levels[i] == input)
                    {
                        cout << usernames[i] << " | " << levels[i] << " | " << trials[i] << endl;
                    }
                }
            }
        }
    }
}