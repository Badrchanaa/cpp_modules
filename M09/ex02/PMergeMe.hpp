#ifndef __PMERGEME_H__
#define __PMERGEME_H__

#include <vector>
#include <cstddef>

class Compare
{
    public:
        static size_t comparisons;
};
size_t Compare::comparisons = 0;

typedef std::vector<unsigned int> array_t;
typedef std::vector<array_t::iterator> iter_array_t;

void    _swapPair(array_t& array, size_t start, size_t pair_size);
void    printVector(array_t arr, size_t level = 1);
bool    _comparePair(array_t& array, size_t start, size_t pair_size);

void   mergeInsertSortVector(array_t& array, size_t level = 1);
void _sortPairs(array_t& array, size_t level);
void _sortPairsFixed(array_t& array, size_t level);
void    mergeToCopy(array_t& copy, array_t array, iter_array_t main, size_t level);
void    mergeToCopy(array_t& copy, iter_array_t main, size_t level);

#endif