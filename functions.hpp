#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <string>
#include <vector>

extern bool guessed;
extern int numberToGuess;
extern bool playing;

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
std::string randomMessage();

#endif
