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

int main()
{
    try{
        Span sp = Span(10);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.longestSpan() << std::endl;
        std::vector<int> n = {10, 34};
        sp.addRange(n.begin(), n.end());
        std::cout << sp.shortestSpan() << std::endl;
    }catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}