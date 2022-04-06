#include "common.h"

#include <algorithm>

string trim(string s)
{
    auto it = remove_if(s.begin(), s.end(), [](char c)
                        { return c == ' '; });
    s.erase(it, s.end());
    return s;
}