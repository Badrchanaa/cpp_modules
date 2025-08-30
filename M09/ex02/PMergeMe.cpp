#include "PMergeMe.hpp"
#include <algorithm>
#include <iostream>


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


bool _compare(array_t& array, size_t first, size_t second)
{
    if (first >= array.size() || second >= array.size())
    {
        std::cerr << "first: " << first << " second: " << second << std::endl;
        throw std::runtime_error("COMPARE: INDEX OUT OF RANGE");
    }
    Compare::comparisons++;
    std::cout << "compare " << array[first] << " and " << array[second] << std::endl;
    std::lower_bound()
    return (array[first] < array[second]);
}
bool _cmp()

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
        std::cout << "\tswap " << first << " <=> " << second << std::endl;
        std::swap(array[first], array[second]);
    }
}


void _insertPend(array_t& main, array_t& pend)
{
    for (array_t::iterator it = pend.begin(); it != pend.end(); it++)
    {
        std::lower_bound(main.begin(), main.end(), *it);
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
    array_t main_values;
    iter_array_t pend; 
    std::cout << " ## after sort main ## " << std::endl;
    printVector(array, level);
    for (size_t i = 0; i < num_of_pairs; i++)
    {
        size_t firstPairLast = level * (2 * i + 1) - 1;
        size_t secondPairLast = firstPairLast + level;
        std::cout << "[Level: " << level << "] main: " << array[secondPairLast] << " pend " << array[firstPairLast] << std::endl;
    }
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
        main_values.push_back(*mainIt);
        pend.push_back(pendIt);
    }
    if (hasOdd)
    {
        size_t odd_index = level * (2 * num_of_pairs + 1) - 1;
        if (odd_index >= array.size())
            throw std::runtime_error("odd index out of range");
        std::cout << "odd is " << array[odd_index] << std::endl;
        pend.push_back(array.begin() + odd_index);
    }
    std::cout << " ## main ## " << std::endl;
    for (iter_array_t::iterator it = main.begin(); it != main.end(); it++)
    {
        std::cout << **it << " ";
    }
    std::cout << std::endl;
    for (iter_array_t::iterator it = pend.begin(); it != pend.end(); it++)
    {
        array_t::value_type pendValue = **it;
        array_t::iterator pos = std::lower_bound(main_values.begin(), main_values.end(), pendValue);
        size_t distance = std::distance(main_values.begin(), pos);
        // std::cout << "value: " << pendValue << " insert pos at " << distance << std::endl;
        iter_array_t::iterator mainPos = main.begin() + distance;
        main.insert(mainPos, *it);
        main_values.insert(pos, pendValue);
    }
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

