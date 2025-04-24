/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:19:29 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/22 12:19:31 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

int main() {
    try {
        std::cout << "--- Basic Test ---\n";
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error in basic test: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing with 10,000 numbers ---\n";
    try {
        Span bigSpan(10000);
        std::srand(static_cast<unsigned int>(std::time(0)));
        for (int i = 0; i < 10000; ++i)
            bigSpan.addNumber(std::rand());

        std::cout << "Shortest Span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span : " << bigSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error in bigSpan test: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing with iterator range ---\n";
    try {
        Span sp(6);
        std::vector<unsigned int> values = {10, 20, 30, 40};
        sp.addRange(values.begin(), values.end());

        sp.addNumber(5);
        sp.addNumber(100);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error in range test: " << e.what() << std::endl;
    }

    std::cout << "\n--- Edge Case: Only One Number ---\n";
    try {
        Span sp(3);
        sp.addNumber(42);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Expected error: " << e.what() << std::endl;
    }

    return 0;
}
