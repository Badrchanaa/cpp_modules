#include "PMergeMe.hpp"
#include <algorithm>
#include <iostream>

void    printVector(array_t arr)
{
    for (array_t::const_iterator it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// arr: [1,2,3,4,5,6,7,8,9,10,11]
// level1: 1->2, 3->4, 5->6, 7->8, 9->10, 11
    // index: 0->1, 2->3, 4->5, 6->7, 8->9, 10
// level2: (1->2)->(3->4), (5->6)->(7->8), 9->10, 11
// level3: ((1->2)->(3->4))->((5->6)->(7->8)), 9->10, 11

// returns first pair < second pair
bool    _comparePair(array_t& array, size_t start, size_t pair_size)
{
    size_t firstPairLast = start + pair_size - 1;
    size_t secondPairLast = firstPairLast + pair_size;
    std::cout << "compare " << firstPairLast << " < " << secondPairLast << std::endl;
    return array[firstPairLast] < array[secondPairLast];
}

void    _swapPair(array_t& array, size_t start, size_t pair_size)
{
    if (pair_size < 1)
        return;

    size_t end = start + pair_size;
    for (size_t i = start; i < end; i++)
    {
        size_t next = i + pair_size;
        std::cout << "swap " << i << " <=> " << next << std::endl;
        std::swap(array[i], array[next]);
    }
}

void    _recurseSort(array_t& array, size_t level)
{
    if (array.size() <= 1)
        return;
    size_t step  = level * 2;
    for (size_t i = 1; i < array.size(); i += step)
    {
        std::cout << "i: " << i << std::endl;
        size_t pairSize = level;
        if (! _comparePair(array, i, pairSize))
            _swapPair(array, i, pairSize);
    }
}

void testSort(array_t& array)
{
    for (int i = 0; i < array.size() - 1; i += 1)
    {
        unsigned int& first = array[i];
        unsigned int& second = array[i + 1];
        if (second > first)
            std::swap(first, second);
    }
}

void    mergeInsertSortVector(array_t& array)
{
    // array_t mainChain; 
    // pairArray_t pairArray;
    // pairArray_t paired;

    if (array.size() <= 1)
        return;
    // for (size_t i = 1; i < array.size(); i += 2)
    // {
    //     elementPair<unsigned int> p;
    //     p.first = array[i - 1];
    //     p.second = array[i];
    //     pairArray.push_back(p);
    //     paired.push_back(p);
    // }
    // _recurseSort(pairArray, 1);
    // should keep track of each pair after sorting
    // mergeInsertSortVector(mainChain);
}