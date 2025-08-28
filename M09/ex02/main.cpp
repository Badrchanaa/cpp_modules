#include "PMergeMe.hpp"
#include <sstream>
#include <iostream>
#include <algorithm>

array_t parseArgs(std::string args)
{
    std::stringstream ss(args);
    array_t arr;

    unsigned int n;
    while ((ss >> n))
    {
        if (std::find(arr.begin(), arr.end(), n) != arr.end())
        {
            std::cerr << "Error: Argument cannot contain duplicates." << std::endl;
            exit(EXIT_FAILURE);
        }
        arr.push_back(n) ;
    }
   if (!ss.eof()) 
   {
    std::cerr << "invalid argument" << std::endl;
    exit(EXIT_FAILURE);
   }
   return arr;
}

void test(array_t vectorArray)
{
    size_t pairSize = 1;
    printVector(vectorArray);
    while (vectorArray.size() / (pairSize * 2) >= 1)
    {
        std::cout << "--> pairsize: " << pairSize << std::endl;
        for (size_t i = 0; i <= vectorArray.size() - pairSize * 2; i+= pairSize * 2)
        {
            size_t firstPairLast = i + pairSize - 1;
            size_t secondPairLast = firstPairLast + pairSize;
            if (vectorArray[firstPairLast] > vectorArray[secondPairLast])
            {
                _swapPair(vectorArray, i, pairSize);
            }
        }
        pairSize *= 2;
    }
    printVector(vectorArray);
}

int main(int ac, char **av)
{
    if (ac == 1)
        return 1;
    
    array_t arr = parseArgs(av[1]);
    test(arr);

    // mergeInsertSortVector(arr);

}