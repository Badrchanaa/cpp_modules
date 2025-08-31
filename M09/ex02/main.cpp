#include "PMergeMe.hpp"
#include <ctime>

template <typename Container> void isSorted(Container& array)
{
    for (size_t i = 0; i < array.size() - 1; i++)
    {
        if (array[i] > array[i + 1])
            throw std::runtime_error("array not sorted");
    }
}

int main(int ac, char **av)
{
    if (ac == 1)
        return 1;
    {
        clock_t start = clock();
        vec_t vector;
        PmergeMe::fillContainer(ac, av, vector);
        mergeInsertSortVector(vector);
        clock_t end = clock();
        std::cout << "std::vector took " << ( double(end - start) / CLOCKS_PER_SEC) * 10e3 << "ms" << std::endl;
        printVector(vector);
        isSorted(vector);
        std::cout << "vector sorted in " << Compare::comparisons << " comparisons" << std::endl;
    } 
    {
        clock_t start = clock();
        deque_t deque;
        PmergeMe::fillContainer(ac, av, deque);
        mergeInsertSortDeque(deque);
        clock_t end = clock();
        std::cout << "std::deque took " << ( double(end - start) / CLOCKS_PER_SEC) * 10e3 << "ms" << std::endl;
        printDeque(deque);
        isSorted(deque);
        std::cout << "deque sorted in " << Compare::comparisons_deque << " comparisons" << std::endl;
    }
    return 0;
    // mergeInsertSortVector(arr);

}