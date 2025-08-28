#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750
#define MY_MAX_VAL 10
int main(int, char**)
{
    std::cout << "THEIR TESTS" << std::endl;
    {
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;//
    }
    std::cout << "MY TESTS" << std::endl;
    {
        Array<int> numbers;
        Array<int> numbers2 = numbers;
        try
        {
            numbers[0];
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    {
        Array<int> numbers(0);
        Array<int> numbers2 = numbers;
        try
        {
            numbers[0];
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    {
        Array<int> numbers(MY_MAX_VAL);

        for (int i = 0; i < MY_MAX_VAL; i++)
        {
            numbers[i] = i * 2;
        }
        Array<int> numbers2;
        numbers2 = numbers;
        std::cout << "numbers size: " << numbers.size() << std::endl;
        std::cout << "numbers2 size: " << numbers.size() << std::endl;
        for (int i = 0; i < MY_MAX_VAL; i++)
        {
            std::cout << "numbers2[" << i << "] = " << numbers2[i] << std::endl;
        }
    }
    return 0;
}
