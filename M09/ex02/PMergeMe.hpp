#ifndef __PMERGEME_H__
#define __PMERGEME_H__

#include <vector>
#include <deque>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>

class Compare
{
    public:
        static size_t comparisons;
        static size_t comparisons_deque;
};

class PmergeMe
{
    public:
        static size_t  jacobsthal(unsigned int n)
        {
            return (
                (pow(2, n + 1) - pow(-1, n + 1)) / 3
            );
        }
        template <typename Container>
        static void fillContainer(int ac, char **av, Container& container)
        {
            std::stringstream ss;
            int n;
            for (int i = 1; i < ac; i++)
            {
                ss.clear();
                ss << av[i];
                // std::cout << "ss: " << ss.str() << std::endl;
                char c;
                if (!(ss >> n) || ss.fail() || (ss >> c))
                {
                    std::cerr << "invalid positive integer: " << av[i] << std::endl;
                    exit(EXIT_FAILURE);
                }
                if (std::find(container.begin(), container.end(), n) != container.end())
                {
                    std::cerr << "Error: Argument cannot contain duplicates." << std::endl;
                    exit(EXIT_FAILURE);
                }
                if (n < 0)
                {
                    std::cerr << "Error: Argument cannot be negative." << std::endl;
                    exit(EXIT_FAILURE);
                }
                ss.str("");
                container.push_back(n) ;
            }
        }
};



typedef std::vector<unsigned int> vec_t;
typedef std::deque<unsigned int> deque_t;

typedef std::vector<vec_t::iterator> iter_vec_t;
typedef std::deque<deque_t::iterator> iter_deque_t;

void    _swapPair(vec_t& array, size_t start, size_t pair_size);
void    printVector(vec_t arr, size_t level = 1);
void    printDeque(deque_t arr, size_t level = 1);

void   mergeInsertSortVector(vec_t& array, size_t level = 1);
void   mergeInsertSortDeque(deque_t& array, size_t level = 1);
void    mergeToCopy(vec_t& copy, iter_vec_t main, size_t level);
void    mergeToCopy(deque_t& copy, iter_deque_t main, size_t level);


#endif