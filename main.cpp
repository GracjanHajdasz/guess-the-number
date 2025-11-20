#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

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

void sortScoreboard()
{
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
    reverse(trials.begin(), trials.end());
    reverse(usernames.begin(), usernames.end());
    reverse(levels.begin(), levels.end());
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
    cout << "tabalica wynikow:" << endl;
    for (int i = 0; i < usernames.size(); i++)
    {
        cout << usernames[i] << " | " << levels[i] << " | " << trials[i] << endl;
    }
}

void welcome()
{
    srand(time(NULL));
    string action;

    cout << "a - rozpocznij gre\nb - tablica wynikow" << endl;
    cin >> action;
    if (action == "a")
    {
        cout << "wybierz poziom trudnosci: latwy[1-50], sredni[1-100], trudny[1-200]" << endl;
        cin >> action;
        if (action == "latwy")
        {
            numberToGuess = rand() % 51;
            level = "latwy";
            playing = true;
        }
        else if (action == "sredni")
        {
            numberToGuess = rand() % 101;
            level = "sredni";
            playing = true;
        }
        else if (action == "trudny")
        {
            numberToGuess = rand() % 201;
            level = "trudny";
            playing = true;
        }
        else
        {
            cout << "nieprawidlowy poziom trudnosci" << endl;
        }
    }
    else if (action == "b")
    {
        viewScoreboard();
    }
    else
    {
        cout << "nieprawidlowa akcja" << endl;
    }
}

void gameplay()
{
    int i = 1;
    while (!guessed)
    {

        int userGuess;

        cout << "proba " << i << " podaj liczbe: ";
        cin >> userGuess;
        if (userGuess < numberToGuess)
        {
            cout << "za malo" << endl;
        }
        else if (userGuess > numberToGuess)
        {
            cout << "za duzo" << endl;
        }
        else
        {
            cout << "odgadles liczbe w " << i << " probie" << endl;
            cout << "podaj swoje imie: ";
            cin >> username;
            guessed = true;
        }
        i++;
    }
    playing = false;
    i--;

    usernames.push_back(username);
    levels.push_back(level);
    trials.push_back(i);
}

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