#include <iostream>

int main(int ac, char *av[])
{
    std::string::size_type i;
    std::string args;

    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (i = 1; (int) i < ac; i++)
        args += av[i];
    for (i = 0; i < args.length(); i++)
        args[i] = toupper(args[i]);
    std::cout << args << std::endl;
    return 0;
}