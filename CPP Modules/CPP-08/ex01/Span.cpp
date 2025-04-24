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

Span::Span(unsigned int N) : N(N) {
    std::cout << "Span constructor called" << std::endl;
}

Span::~Span() {
    std::cout << "Span destructor called" << std::endl;
}

Span::Span(const Span& copy) {
    *this = copy;
    std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(const Span& copy) {
    if (this != &copy) {
        this->N = copy.N;
        this->v = copy.v;
    }
    return *this;
}

void Span::addNumber(unsigned int number) {
    if (v.size() >= N)
        throw std::overflow_error("Span is full");
    v.push_back(number);
}

unsigned int Span::shortestSpan() {
    if (v.size() <= 1)
        throw std::overflow_error("Not enough elements to compute span");

    std::vector<unsigned int> temp = v;
    std::sort(temp.begin(), temp.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    for (size_t i = 1; i < temp.size(); ++i) {
        unsigned int diff = temp[i] - temp[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

unsigned int Span::longestSpan() {
    if (v.size() <= 1)
        throw std::overflow_error("Not enough elements to compute span");

    auto [minIt, maxIt] = std::minmax_element(v.begin(), v.end());
    return *maxIt - *minIt;
}


