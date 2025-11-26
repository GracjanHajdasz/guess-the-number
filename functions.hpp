#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>
#include <vector>

extern int numberToGuess;
extern int bet;

extern bool guessed;
extern bool playing;
extern bool isBetMode;

extern std::string username;
extern std::string level;
extern std::string userTrials;
extern std::vector<std::string> usernames;
extern std::vector<std::string> levels;
extern std::vector<int> trials;

void sortScoreboard();
void viewScoreboard();
void welcome();
void gameplay();
void betMode();
std::string randomMessage();
void readFile();
void writeToFile();

#endif
