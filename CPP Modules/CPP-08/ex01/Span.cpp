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

Span::Span(unsigned int N): N(N) {
    std::cout << "Span construtor called" << std::endl;
}

Span::~Span(){
    std::cout << "Span destrutor called" << std::endl;
}

Span::Span(const Span &copy){
    *this = copy;
    std::cout  << "Span copy construtor called" << std::endl;
}

Span &Span::operator=(const Span &copy){
    if (this != &copy){
        this->N = copy.N;
        this->v = copy.v;
    }
    return (*this);
}

void Span::addNumber(unsigned int number){
    if (v.size() >= N)
        throw std::overflow_error("Span is full");
    v.push_back(number);
    //std::cout << "Number add to Span" << std::endl;
}

unsigned int Span::shortestSpan(){
    if (v.size() <= 1)
        throw std::overflow_error("Span empty or only one element");
    std::vector<unsigned int> n;
    int len = v.size();
    for (int i = 0; i < len; i++){
        int j = -1;
        while(++j < len)
        {
            if (v[i] < v[len - j - 1])
                n.push_back(abs(v[len - j - 1] - v[i]));
        }
    }
    auto min = std::min_element(n.begin(), n.end());
    unsigned int min_x = static_cast<unsigned int>(*min);
    return (*min);
}

unsigned int Span::longestSpan(){
    if (v.size() <= 1)
        throw std::overflow_error("Span empty or only one element");
    std::vector<unsigned int> n;
    int len = v.size();
    for (int i = 0; i < len; i++){
        int j = -1;
        while(++j < len)
        {
            if (v[i] < v[len - j - 1])
                n.push_back(abs(v[len - j - 1] - v[i]));
        }
    }
    auto max = std::max_element(n.begin(), n.end());
    unsigned int max_x = static_cast<unsigned int>(*max);
    return (*max);
}




