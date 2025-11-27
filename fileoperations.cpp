#include <iostream>
#include <string>
#include "functions.hpp"
#include <fstream>

using namespace std;

void writeToFile() {
    ofstream file("scoreboard.txt");

    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku scoreboard.txt do zapisu" << endl;
        return;
    }
    else {
        for (int i = 0; i < usernames.size(); i++) {
            file << usernames[i] << "," << levels[i] << "," << to_string(trials[i]) << endl;
        }
    }

    file.close();
}

void readFile() {
    ifstream file("scoreboard.txt");

    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku scoreboard.txt" << endl;
        return;
    }
    else {
        string uname, lvl, trl; // username, level, trials as strings
        string text;

        usernames.clear();
        levels.clear();
        trials.clear();

        while (getline(file, text)) {
            size_t pos1 = text.find(",");
            size_t pos2 = text.find(",", pos1 + 1);

            // pobieranie wartosci
            uname = text.substr(0, pos1);
            lvl = text.substr(pos1 + 1, pos2 - pos1 - 1);
            trl = text.substr(pos2 + 1);

            // dodawanie do wektorow
            usernames.push_back(uname);
            levels.push_back(lvl);
            trials.push_back(stoi(trl));
        }
    }

    file.close();
}