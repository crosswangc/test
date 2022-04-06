#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Add {
public:
    Add(const T &v) : addValue(v) {}
    void operator()(T &elem) const { elem += addValue; }

private:
    T addValue;
};

template <typename T>
class MeanValue
{
public:
    MeanValue() : num(0), sum(0) {}
    void operator() (const T& elem) {
        num++;
        sum += elem;
    }
    operator double() {
        return static_cast<double>(sum) / static_cast<double>(num);
    }

private:
    T num;
    T sum;
};

string trim(string s);

template <typename T>
bool absLess(const T& elem1, const T& elem2) {
    return abs(elem1) < abs(elem2);
}

// INSERT_ELEMENTS (collection, first, last)
// - fill values from first to last into the collection
// - NOTE: NO half-open range
template <typename T>
inline void INSERT_ELEMENTS(T &coll, int first, int last)
{
    for (int i = first; i <= last; ++i)
    {
        coll.insert(coll.end(), i);
    }
}

// PRINT_ELEMENTS()
// - prints optional string optcstr followed by
// - all elements of the collection coll
// - separated by spaces
template <typename T>
inline void PRINT_ELEMENTS(const T &coll,
                           const std::string &optcstr = "")
{
    std::cout << optcstr;
    for (auto elem : coll)
    {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}

// PRINT_MAPPED_ELEMENTS()
// - prints optional string optcstr followed by
// - all elements of the key/value collection coll
// - separated by spaces
template <typename T>
inline void PRINT_MAPPED_ELEMENTS(const T &coll,
                                  const std::string &optcstr = "")
{
    std::cout << optcstr;
    for (auto elem : coll)
    {
        std::cout << '[' << elem.first
                  << ',' << elem.second << "] ";
    }
    std::cout << std::endl;
}

#endif