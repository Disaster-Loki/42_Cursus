/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:41:53 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/15 11:41:54 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cerrno>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &coppy) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy){ return (*this); }

void ScalarConverter::convert(const std::string &input) {
    if (input == "nan" || input == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }

    if (input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff") {
        std::string sign = (input[0] == '-') ? "-" : "+";
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << sign << "inff" << std::endl;
        std::cout << "double: " << sign << "inf" << std::endl;
        return;
    }

    if (input.length() == 1 && !std::isdigit(input[0])) {
        char c = input[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
        return;
    }

    char c;
    int i;
    float f;
    double d;

    bool is_float = input.find('f') != std::string::npos;
    std::string value = input;

    if (is_float)
        value = input.substr(0, input.length() - 1);
    try {
        d = std::stod(value);
        f = static_cast<float>(d);
        i = static_cast<int>(d);
        c = static_cast<char>(i);

        if (d < 0 || d > 127 || std::isnan(d))
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(c))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << c << "'" << std::endl;
        if (d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()) || std::isnan(d))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    } catch (...) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
