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

void welcome()
{
    srand(time(NULL));
    string action;

    cout << "a - rozpocznij gre\n";
    if (usernames.size() > 0)
        cout << "b - wyswietl tablice wynikow\n";
    cin >> action;
    if (action == "a")
    {
        cout << "wybierz poziom trudnosci: latwy[1-50], sredni[1-100], trudny[1-200]" << endl;
        cin >> action;
        if (action == "latwy")
        {
            numberToGuess = rand() % 51;
            level = "latwy";
            betMode();
            playing = true;
        }
        else if (action == "sredni")
        {
            numberToGuess = rand() % 101;
            level = "sredni";
            betMode();
            playing = true;
        }
        else if (action == "trudny")
        {
            numberToGuess = rand() % 201;
            level = "trudny";
            betMode();
            playing = true;
        }
        else
        {
            cout << "nieprawidlowy poziom trudnosci" << endl;
        }
    }
    else if (action == "b")
    {
        while (true)
        {
            viewScoreboard();
            cout << "wrocic do menu? (t/n): ";
            cin >> action;
            if (action == "t")
                break;
        }
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
        string input;
        cout << "proba " << i << " podaj liczbe: ";
        cin >> input;

        // sprawdzanie czy podana wartosc jest liczba
        bool typeCheck = true;
        for (int i = 0; i < input.size(); i++)
        {
            char c = input[i];
            if (!isdigit(c))
            {
                typeCheck = false;
                break;
            }
        }

        if (!typeCheck)
        {
            cout << "Podana wartosc nie jest liczba!" << endl;
            continue;
        }

        int userGuess = stoi(input);

        // rozgrywaka
        if (userGuess < numberToGuess)
        {
            cout << "za malo " << randomMessage() << endl;
        }
        else if (userGuess > numberToGuess)
        {
            cout << "za duzo " << randomMessage() << endl;
        }
        else
        {
            cout << "odgadles liczbe w " << i << " probie" << endl;
            cout << "podaj swoje imie: ";
            cin >> username;
            guessed = true;
        }

        i++;

        if (isBetMode && i > bet)
        {
            cout << "przekroczyles liczbe prob z trybu zakladow, przegrales zaklad!" << endl;
            isBetMode = false;
        }
    }

    playing = false;
    if (isBetMode && i <= bet)
        cout << "wygrales zaklad!" << endl;
    i--;

    usernames.push_back(username);
    levels.push_back(level);
    trials.push_back(i);
    writeToFile();
}

void betMode()
{
    string input;
    cout << "czy chcesz zagrac w trybie zakladow? (t/n): ";
    cin >> input;

    if (input == "t")
    {
        isBetMode = true;
        cout << "tryb zakladow wlaczony!" << endl;
        cout << "w ile prob odgadniesz liczbe? ";
        cin >> bet;
    }
    else if (input == "n")
    {
        isBetMode = false;
    }
    else
    {
        cout << "nieprawidlowa odpowiedz, tryb zakladow wylaczony" << endl;
        isBetMode = false;
    }
}

string randomMessage()
{
    srand(time(NULL));
    int i = rand() % 4;

    vector<string> messages = {
        "Dobry strzal!",
        "Nastepnym razem sie uda!",
        "Nie poddawaj sie!",
        "Juz blisko!"};
    return messages[i];
}