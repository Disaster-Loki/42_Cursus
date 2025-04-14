#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>

class ScalarConverter
{
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &coppy);
        ScalarConverter &operator=(const ScalarConverter &copy);
        static void convert(const std::string &input);
};

#endif