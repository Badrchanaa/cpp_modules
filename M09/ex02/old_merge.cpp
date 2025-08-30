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

// bool    _comparePair(array_t& array, size_t start, size_t pair_size)
// {
    // size_t firstPairLast = start + pair_size - 1;
    // size_t secondPairLast = firstPairLast + pair_size;
    // size_t firstPairA =  pair_size * start;
    // std::cout << "compare " << firstPairLast << " < " << secondPairLast << std::endl;
    // return array[firstPairLast] < array[secondPairLast];
// }

// bool _comparePair(array_t&array, size_t index, size_t pair_size)
// {
//     size_t pairA = pair_size * index;
//     size_t pairB = pairA + pair_size / 2;
//     std::cout << "Compare" << std::endl;
//     std::cout << "Pair Size: " << pair_size << " | index: " << index << std::endl;
//     std::cout << "pairA: " << pairA << " | pairB: " << pairB << std::endl;
//     if (pairA >= array.size() || pairB >= array.size())
//     {
//         throw std::runtime_error("compare pair out of range");
//     }
//     return (array[pairA] > array[pairB]);
// }

bool _compare(array_t& array, size_t first, size_t second)
{
    if (first >= array.size() || second >= array.size())
    {
        std::cerr << "first: " << first << " second: " << second << std::endl;
        throw std::runtime_error("COMPARE: INDEX OUT OF RANGE");
    }
    return (array[first] < array[second]);
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

// void    _sortPairs(array_t& array, size_t level)
// {
//     size_t num_of_pairs = array.size() / level;
//     if (array.size() <= 1)
//         throw std::runtime_error("unexpected state reached");
//     if (num_of_pairs <= 1)
//         return;
//     size_t pairSize = level;
//     for (size_t i = 0; i < num_of_pairs; i++)
//     {
//         std::cout << "i: " << i << std::endl;
//         _comparePair(array, i, pairSize);
//             _swapPair(array, i, pairSize / 2);
//     }
// }

void _insertPend(array_t& main, array_t& pend)
{
    for (array_t::iterator it = pend.begin(); it != pend.end(); it++)
    {
        std::lower_bound(main.begin(), main.end(), *it);
    }
}

void    mergeInsertSortVector(array_t& array, size_t level)
{

    // level starts with 1

    // size_t num_of_pairs = array.size() / level;
    size_t num_of_pairs = array.size() / (level * 2);
    std::cout << "size: " << array.size() << " pairs count: " << num_of_pairs << std::endl;

    if (num_of_pairs <= 1)
        return;
    for (size_t i = 0; i < num_of_pairs; i++)
    {
        size_t firstPairLast = level * (2 * i + 1) - 1;
        size_t secondPairLast = firstPairLast + level;
        if (!_compare(array, firstPairLast, secondPairLast))

    }
    mergeInsertSortVector(array, level * 2);
}


// array_t mergeInsertSortVector(array_t& array)
// {
//     array_t main;
//     array_t pend;

//     if (array.size() <= 1)
//         return array;

//     bool hasOdd = array.size() % 2 != 0;

//     for (size_t i = 0; i < array.size() - 1; i += 2)
//     {
//         array_t::value_type first = array[i];
//         array_t::value_type second = array[i + 1];
//         if (first > second)
//         {
//             main.push_back(first);
//             pend.push_back(second);
//         }
//         else
//         {
//             main.push_back(second);
//             pend.push_back(first);
//         }
//     }
//     if (hasOdd)
//         pend.push_back(array[array.size() - 1]);

//     main = mergeInsertSortVector(main);
    
//     for (array_t::iterator it = pend.begin(); it != pend.end(); it++)
//     {
//         array_t::iterator it_f = std::lower_bound(main.begin(), main.end(), *it);
//         main.insert(it_f, *it);
//     }
//     return main;
// }

// array_t mergeInsertSortVector(array_t array, size_t level)
// {
//     // check if only one pair ? do not sort
//     std::cout << "sort. level: " << level << std::endl;
//     size_t size = array.size();

//     size_t num_of_pairs = array.size() / (level);

//     std::cout << "num_of_pairs:" << num_of_pairs << std::endl;
//     if (num_of_pairs <= 1)
//     {
//         std::cout << " -------------- out < 1 (level: "<< level << ") --------------" << std::endl;
//         return array;
//     }

//     size_t leftoversSize = array.size() % (level);
//     array_t::value_type leftOver = -42;
//     if (leftoversSize > 0)
//     {
//         size_t leftoverIndex = ((num_of_pairs) * (level));
//         if (leftoverIndex >= array.size())
//         {
//             std::cerr << "index: " << leftoverIndex << std::endl;
//             throw std::runtime_error("left over index out of range");
//         }
//         leftOver = array[leftoverIndex];
//     }
//     // _sortPairs(array, level);
//     array_t newArray = mergeInsertSortVector(array, level * 2);
//     size_t count = 0;
//     array_t bChain;
//     array_t mainChain;
//     array_t result;
//     std::cout << "merge. level: " << level << std::endl;
//     for (size_t i = 0; i < num_of_pairs; i++)
//     {
//         size_t a_index = level * i;
//         size_t b_index = a_index + level / 2;
//         std::cout << "pairs: " << num_of_pairs << " b_index: " << b_index << " a_index: " << a_index << std::endl;
//         if (a_index >= newArray.size() || b_index >= newArray.size())
//             throw std::runtime_error("a/b index out of range");
//         if (b_index >= newArray.size())
//             throw std::runtime_error("pend chain index out of range");
//         bChain.push_back(newArray[b_index]);
//         mainChain.push_back(newArray[a_index]);
//         count += 2;
//     }
//     count += leftoversSize;
//     std::copy(mainChain.begin(), mainChain.end(), std::back_inserter(result));
//     std::copy(bChain.begin(), bChain.end(), std::back_inserter(result));
//     std::cout << "leftovers: " << leftoversSize << std::endl;
//     if (result.size() != count - leftoversSize)
//     {
//      std::cout << "count is " << count << " | size is " << size << std::endl;
//      throw std::runtime_error("array size mismatch");
//     }
//    return result;
// }

// array_t mergeInsertSortVector(array_t array, size_t level)
// {
//     size_t arrSize = array.size();
//     array_t mainChain; 
//     std::cout << "entered with level: " << level << " SIZE: " << array.size() << std::endl;
//     size_t num_of_pairs = array.size() / (level);
//     std::cout << "num_of_pairs:" << num_of_pairs << std::endl;
//     if (num_of_pairs <= 1)
//     {
//         std::cout << " -------------- out < 1 (level: "<< level << ") --------------" << std::endl;
//         return array;
//     }
//     _sortPairs(array, level);
//     array_t leftovers;
//     size_t leftoversSize = array.size() % (level);
//     array_t::value_type leftOver = -42;
//     if (leftoversSize > 0)
//     {
//         size_t leftoverIndex = ((num_of_pairs) * (level));
//         if (leftoverIndex >= array.size())
//         {
//             std::cerr << "index: " << leftoverIndex << std::endl;
//             throw std::runtime_error("left over index out of range");
//         }
//         leftOver = array[leftoverIndex];
//     }
//     std::string s;
//     std::cout << "leftovers: " << leftoversSize << std::endl;

//     std::cout << "[LEVEL " << level << "] mainChain.size: " << mainChain.size() << std::endl;
//     // recursively sort the main chain
//     array = mergeInsertSortVector(array, level * 2);
//     array_t bChain;
//     array_t sorted;
//     for (size_t i = 0; i < num_of_pairs; i++)
//     {
//         size_t a_index = level * i;
//         size_t b_index = a_index + level / 2;
//         if (a_index >= array.size() || b_index >= array.size())
//             throw std::runtime_error("a/b index out of range");
//         if (b_index >= array.size())
//             throw std::runtime_error("pend chain index out of range");
//         bChain.push_back(array[b_index]);
//         mainChain.push_back(array[a_index]);
//     }
//     // mainChain.insert(mainChain.begin(), bChain[0]);
//     // bChain.erase(bChain.begin());
//     std::cout << "array size: " << array.size() << " | mainChain.size: " << mainChain.size() << " | bChain.size: " << bChain.size() << std::endl;
//     int count = 0;
//     for (array_t::iterator it = mainChain.begin(); it != mainChain.end(); it++)
//     {
//         count++;
//         sorted.push_back(*it);
//     }
//     std::cout << "[LEVEL " << level << "] inserted " << count << " elements from main chain" << std::endl;
//     for (array_t::iterator it = bChain.begin(); it != bChain.end(); it++)
//     {
//         count++;
//         sorted.push_back(*it);
//     }
//     std::cout << "[LEVEL " << level << "] inserted " << count << " total elements" << std::endl;
//     if (leftoversSize > 0)
//         sorted.push_back(leftOver);
//     if (array.size() != arrSize)
//         std::cout << "something went wrong from " << arrSize << " to " << array.size() << std::endl;
//     std::cout << "[LEVEL " << level << "] sorted size: " << sorted.size() << "expected size: " << array.size() << std::endl;
//     if (sorted.size() != array.size())
//         throw std::runtime_error("something got lost or duplicated");
//     std::cout << " -------------- out (level: "<< level << ") --------------" << std::endl;
//     return sorted;
// }

