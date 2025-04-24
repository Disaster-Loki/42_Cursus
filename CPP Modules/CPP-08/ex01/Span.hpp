/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:19:37 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/22 12:19:38 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <iterator>

class Span {
private:
    unsigned int N;
    std::vector<unsigned int> v;

public:
    Span(unsigned int N);
    ~Span();
    Span(const Span& copy);
    Span& operator=(const Span& copy);

    void addNumber(unsigned int number);
    unsigned int shortestSpan();
    unsigned int longestSpan();

    template <typename Iter>
    void addRange(Iter begin, Iter end) {
        if (std::distance(begin, end) + v.size() > N)
            throw std::runtime_error("Range out of bounds");
        v.insert(v.end(), begin, end);
    }
};

#endif

