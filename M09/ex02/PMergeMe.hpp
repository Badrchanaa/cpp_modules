#ifndef __PMERGEME_H__
#define __PMERGEME_H__

#include <vector>
#include <cstddef>

template <typename T>
struct elementPair: public std::pair<T, T>
{
    bool operator<(const elementPair& p) const
    {
        return this->first < p.first;
    }
    bool operator>(const elementPair& p) const
    {
        return this->first > p.first;
    }
    bool operator==(const elementPair& p) const
    {
        return this->first == p.first;
    }
    bool operator!=(const elementPair& p) const
    {
        return !(*this == p);
    }
};

typedef std::vector<unsigned int> array_t;
typedef std::vector<elementPair<unsigned int> > pairArray_t;

void    _swapPair(array_t& array, size_t start, size_t pair_size);
void    printVector(array_t arr);
bool    _comparePair(array_t& array, size_t start, size_t pair_size);

void    mergeInsertSortVector(array_t& array);

#endif