#include "ScalarConverter.hpp"

int main(int av, char **args)
{
    if (av != 2)
    {
        std::cout << "convert [string]" << std::endl;
        return (1);
    }
    ScalarConverter sc;
    sc.convert(args[1]);
    return (0);
}