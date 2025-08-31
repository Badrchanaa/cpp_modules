#include "PMergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <cmath>

size_t Compare::comparisons_deque = 0;

void    printDeque(deque_t arr, size_t level)
{
    std::cout << "LEVEL: " << level << std::endl;;
    std::cout << "\t";
    for (deque_t::const_iterator it = arr.begin(); it != arr.end(); ++it)
    {

        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


bool _compare(deque_t& array, size_t first, size_t second)
{
    Compare::comparisons_deque++;
    return (array[first] < array[second]);
}


bool _cmpIterator(const deque_t::iterator& lit, const deque_t::iterator& rit)
{
    Compare::comparisons_deque++;
    return (*lit < *rit);
}

void    _swapPair(deque_t& array, size_t index, size_t level)
{
    size_t start = index * (level * 2);
    for (size_t i = 0; i < level; i++)
    {
        size_t first = start + i;
        size_t second = start +  i + level;
        std::swap(array[first], array[second]);
    }
}

void _insertPend(iter_deque_t& main, iter_deque_t& pend)
{
    if (pend.size() == 0)
        return;
    unsigned int n;
    n = 2;
    iter_deque_t::iterator it = pend.begin();
    main.insert(main.begin(), *it);
    pend.erase(it);
    size_t jacobsthalIndex = PmergeMe::jacobsthal(n);
    size_t prevJacob = PmergeMe::jacobsthal(n - 1);
    size_t jacobDiff = jacobsthalIndex - prevJacob;
    size_t insertCount = 0;
    iter_deque_t::iterator end = main.begin() + jacobsthalIndex + insertCount;
    while (jacobDiff <= pend.size())
    {
        for (long i = jacobDiff - 1; i >= 0; i--)
        {
            iter_deque_t::iterator it = pend.begin() + i;
            if (jacobsthalIndex + insertCount < main.size())
                end = main.begin() + jacobsthalIndex + insertCount;
            else
                end = main.end();
            iter_deque_t::iterator pos = std::upper_bound(main.begin(), end, *it, _cmpIterator);
            main.insert(pos, *it);
            pend.erase(it);
        }
        n++;
        insertCount += jacobDiff;
        prevJacob = jacobsthalIndex;
        jacobsthalIndex = PmergeMe::jacobsthal(n);
        jacobDiff = jacobsthalIndex - prevJacob;
    }
    for (iter_deque_t::reverse_iterator it = pend.rbegin(); it != pend.rend(); it++)
    {
        iter_deque_t::iterator pos = std::upper_bound(main.begin(), main.end(), *it, _cmpIterator);
        main.insert(pos, *it);
    }
}

// level starts at 1
void    mergeInsertSortDeque(deque_t& array, size_t level)
{
    size_t num_of_pairs = array.size() / (level * 2);
    if (num_of_pairs * 2 <= 1)
        return;
    bool hasOdd = (array.size() % (level * 2)) >= level;
    for (size_t i = 0; i < num_of_pairs; i++)
    {
        size_t firstPairLast = level * (2 * i + 1) - 1;
        size_t secondPairLast = firstPairLast + level;
        if (!_compare(array, firstPairLast, secondPairLast))
            _swapPair(array, i, level);
    }
    mergeInsertSortDeque(array, level * 2);
    iter_deque_t main; 
    iter_deque_t pend; 

    deque_t::iterator start = array.begin();
    for (size_t i = 0; i < num_of_pairs; i++)
    {
        deque_t::iterator pendIt = start;
        std::advance(pendIt, level * (2 * i + 1) - 1);
        deque_t::iterator mainIt = pendIt;
        std::advance(mainIt, level);
        main.push_back(mainIt);
        pend.push_back(pendIt);
    }
    if (hasOdd)
        pend.push_back(array.begin() + level * (2 * num_of_pairs + 1) - 1);
    _insertPend(main, pend);
    deque_t copy;

    mergeToCopy(copy, main, level);
    deque_t::iterator arrIt = array.begin();
    for (deque_t::iterator it = copy.begin(); it != copy.end(); it++)
    {
        *arrIt = *it;
        arrIt++;
    }
}

void    mergeToCopy(deque_t& copy, iter_deque_t main, size_t level)
{
    for (iter_deque_t::iterator it = main.begin(); it != main.end(); it++)
    {
        deque_t::iterator chunkEnd = *it + 1;
        // std::cout << "insert main: " << **it << std::endl;
        deque_t::iterator chunkStart = chunkEnd - level;
        // std::cout << "\t";
        for (deque_t::iterator it2 = chunkStart; it2 != chunkEnd; it2++)
        {
            // std::cout << *it2 << " ";
            copy.push_back(*it2);
        }
            // std::cout << std::endl;
    }
    // std::cout << " ## Copy ## " <<std::endl;
}

