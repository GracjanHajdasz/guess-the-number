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

void writeToFile() {
    ofstream file("scoreboard.txt");

    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku scoreboard.txt do zapisu" << endl;
        return;
    } else {
        for (int i = 0; i < usernames.size(); i++) {
            file << usernames[i] << "," << levels[i] << "," <<to_string(trials[i]) << endl;
        }
    }

    file.close();
}

void readFile() {
    ifstream file("scoreboard.txt");
    
    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku scoreboard.txt" << endl;
        return;
    } else {
        string uname, lvl, trl;  //username, level, trials as strings
        string text;

        usernames.clear();
        levels.clear();
        trials.clear();

        while (getline(file, text)) {
            size_t pos1 = text.find(",");
            size_t pos2 = text.find(",", pos1 + 1);
            
            //pobieranie wartosci
            uname = text.substr(0, pos1);
            lvl = text.substr(pos1 + 1, pos2 - pos1 - 1);
            trl = text.substr(pos2 + 1);
            
            //dodawanie do wektorow
            usernames.push_back(uname);
            levels.push_back(lvl);
            trials.push_back(stoi(trl));
        }
    }
    
    file.close();
}

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
            if(count(levels.begin(), levels.end(), input) == 0)
            {
                cout << "brak wynikow dla podanego poziomu trudnosci" << endl;
                return;
            } else {
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

        if (isBetMode && i > bet){
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