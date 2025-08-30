#include "PMergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <cmath>

size_t Compare::comparisons = 0;

void    printVector(array_t arr, size_t level)
{
    std::cout << "LEVEL: " << level << std::endl;;
    std::cout << "\t";
    for (array_t::const_iterator it = arr.begin(); it != arr.end(); ++it)
    {

        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

size_t  jacobsthal(unsigned int n)
{
    return (
        (pow(2, n + 1) - pow(-1, n + 1)) / 3
    );
}

bool _compare(array_t& array, size_t first, size_t second)
{
    if (first >= array.size() || second >= array.size())
    {
        std::cerr << "first: " << first << " second: " << second << std::endl;
        throw std::runtime_error("COMPARE: INDEX OUT OF RANGE");
    }
    Compare::comparisons++;
    std::cout << "compare " << array[first] << " and " << array[second] << std::endl;
    return (array[first] < array[second]);
}


bool _cmpIterator(const array_t::iterator& lit, const array_t::iterator& rit)
{
    Compare::comparisons++;
    std::cout << "[bs] compare " << *lit << " and " << *rit << std::endl;
    return (*lit < *rit);
}

void    _swapPair(array_t& array, size_t index, size_t level)
{
    // size_t end = (index * pair_size) + pair_size / 2;
    // size_t start = (index * pair_size) + 
    size_t start = index * (level * 2);
    for (size_t i = 0; i < level; i++)
    {
        size_t first = start + i;
        size_t second = start +  i + level;
        if (first >= array.size() || second >= array.size())
        {
        std::cerr << "first: " << first << " second: " << second << std::endl;
            throw std::runtime_error("SWAP: INDEX OUT OF RANGE");
        }
        // std::cout << "\tswap " << first << " <=> " << second << std::endl;
        std::swap(array[first], array[second]);
    }
}

void _insertPend(iter_array_t& main, iter_array_t& pend)
{
    if (pend.size() == 0)
        return;
    unsigned int n;
    n = 2;
    iter_array_t::iterator it = pend.begin();
    std::cout << "first pend size: " << pend.size() << std::endl;
    main.insert(main.begin(), *it);
    pend.erase(it);
    size_t jacobsthalIndex = jacobsthal(n);
    size_t prevJacob = jacobsthal(n - 1);
    size_t jacobDiff = jacobsthalIndex - prevJacob;
    std::cout << "pend size: " << pend.size() << " jacob: " << jacobsthalIndex << std::endl;
    size_t insertCount = 0;
    std::cout << "diff: " << jacobDiff << " curr: " << jacobsthalIndex << std::endl;
    iter_array_t::iterator end = main.begin() + jacobsthalIndex + insertCount;
    while (jacobDiff <= pend.size())
    {
        for (long i = jacobDiff - 1; i >= 0; i--)
        {
            iter_array_t::iterator it = pend.begin() + i;
            if (jacobsthalIndex + insertCount < main.size())
                end = main.begin() + jacobsthalIndex + insertCount;
            else
                end = main.end();
            std::cout << "search to: " << std::distance(main.begin(), end) << std::endl;
            iter_array_t::iterator pos = std::upper_bound(main.begin(), end, *it, _cmpIterator);
            std::cout << "insert : " << **it << std::endl;
            main.insert(pos, *it);
            // if (static_cast<size_t>(std::distance(main.begin(), inserted)))
            //     offset++;
            // end = main.begin() + jacobsthalIndex + insertCount - offset;
            pend.erase(it);
        }
        n++;
        insertCount += jacobDiff;
        prevJacob = jacobsthalIndex;
        jacobsthalIndex = jacobsthal(n);
        jacobDiff = jacobsthalIndex - prevJacob;
        std::cout << "diff: " << jacobDiff << " curr: " << jacobsthalIndex << std::endl;
    }
    for (iter_array_t::reverse_iterator it = pend.rbegin(); it != pend.rend(); it++)
    {
        iter_array_t::iterator pos = std::upper_bound(main.begin(), main.end(), *it, _cmpIterator);
        iter_array_t::iterator inserted = main.insert(pos, *it);
        std::cout << "inserted at " << std::distance(main.begin(), inserted) << " size: " << main.size() << std::endl;
    }
}

// level starts at 1
void    mergeInsertSortVector(array_t& array, size_t level)
{
    // size_t num_of_pairs = array.size() / level;
    size_t num_of_pairs = array.size() / (level * 2);
    std::cout << " #### size: " << array.size() << " pairs count: " << num_of_pairs << " #### " << std::endl;
    if (num_of_pairs * 2 <= 1)
        return;
    bool hasOdd = (array.size() % (level * 2)) >= level;

    if (hasOdd)
    {
        std::cout << "\tLevel " << level << " has odd number " << std::endl;
    }

    for (size_t i = 0; i < num_of_pairs; i++)
    {
        size_t firstPairLast = level * (2 * i + 1) - 1;
        size_t secondPairLast = firstPairLast + level;
        if (!_compare(array, firstPairLast, secondPairLast))
            _swapPair(array, i, level);
    }
    mergeInsertSortVector(array, level * 2);
    iter_array_t main; 
    iter_array_t pend; 
    std::cout << " ## after sort main ## " << std::endl;
    printVector(array, level);

    array_t::iterator start = array.begin();
    std::cout << " ## with iterators ## " << std::endl;
    for (size_t i = 0; i < num_of_pairs; i++)
    {
        array_t::iterator pendIt = start;
        // size_t distance = std::distance(start, array.end());
        std::advance(pendIt, level * (2 * i + 1) - 1);
        array_t::iterator mainIt = pendIt;
        std::advance(mainIt, level);
        std::cout << "[Level: " << level << "] main: " << *mainIt << " pend " << *pendIt << std::endl;
        main.push_back(mainIt);
        pend.push_back(pendIt);
    }
    if (hasOdd)
    {
        size_t odd_index = level * (2 * num_of_pairs + 1) - 1;
        if (odd_index >= array.size())
            throw std::runtime_error("odd index out of range");
        pend.push_back(array.begin() + odd_index);
        // iter_array_t::iterator pos = std::lower_bound(main.begin(), main.end(), array.begin() + odd_index, _cmpIterator);
        // main.insert(pos, array.begin() + odd_index);
    }
    std::cout << " ## main ## " << std::endl;
    for (iter_array_t::iterator it = main.begin(); it != main.end(); it++)
    {
        std::cout << **it << " ";
    }
    std::cout << std::endl;
    _insertPend(main, pend);
    std::cout << " ## merged main ## " << std::endl;
    for (iter_array_t::iterator it = main.begin(); it != main.end(); it++)
    {
        std::cout << **it << " ";
    }
    array_t copy;
    copy.reserve(array.size());

    mergeToCopy(copy, main, level);
    array_t::iterator arrIt = array.begin();
    for (array_t::iterator it = copy.begin(); it != copy.end(); it++)
    {
        *arrIt = *it;
        arrIt++;
    }
    std::cout << std::endl;
}

void    mergeToCopy(array_t& copy,iter_array_t main, size_t level)
{
    for (iter_array_t::iterator it = main.begin(); it != main.end(); it++)
    {
        // for each element in main chain i should merge its values to copy
        array_t::iterator chunkEnd = *it + 1;
        std::cout << "insert main: " << **it << std::endl;
        array_t::iterator chunkStart = chunkEnd - level;
        std::cout << "\t";
        for (array_t::iterator it2 = chunkStart; it2 != chunkEnd; it2++)
        {
            std::cout << *it2 << " ";
            copy.push_back(*it2);
        }
            std::cout << std::endl;
    }
    std::cout << " ## Copy ## " <<std::endl;
    printVector(copy);
}

