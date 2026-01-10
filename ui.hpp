#ifndef UI_HPP
#define UI_HPP

#include <string>

namespace UI
{
    void clear();
    void pause();
    void header(const std::string &title);
    void menu();
    void info(const std::string &text);
    void error(const std::string &text);
}

#endif
