#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

bool guessed = false;
int numberToGuess;

void scoreboard()
{
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
        }
        else if (action == "sredni")
        {
            numberToGuess = rand() % 101;
        }
        else if (action == "trudny")
        {
            numberToGuess = rand() % 201;
        }
        else
        {
            cout << "nieprawidlowy poziom trudnosci" << endl;
        }
    }
}

void gameplay()
{
    int i = 1;
    while (!guessed)
    {

        int userGuess;
        string username;

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
}

int main()
{

    while (true)
    {
        welcome();
        gameplay();
        guessed = false;
    }

    system("pause");
    return 0;
}