#include "ui.hpp"
#include "functions.hpp"
#include <iostream>

namespace UI
{

    void clear()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    void pause()
    {
        std::cout << "\nNacisnij ENTER aby kontynuowac...";
        std::cin.ignore();
        std::cin.get();
    }

    void header(const std::string &title)
    {
        std::cout << "+------------------------------------+\n";
        std::cout << "| " << title;
        for (size_t i = title.length(); i < 34; i++)
            std::cout << " ";
        std::cout << "|\n";
        std::cout << "+------------------------------------+\n";
    }

    void menu()
    {
        std::cout << "\n";
        std::cout << "[1] Rozpocznij gre\n";
        if (usernames.size() > 0)
            std::cout << "[2] Tablica wynikow\n";
        std::cout << "[0] Wyjscie\n";
        std::cout << "\nTwoj wybor: ";
    }

    void info(const std::string &text)
    {
        std::cout << text << "\n";
    }

    void error(const std::string &text)
    {
        std::cout << text << "\n";
    }
}
