/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:32:18 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/11 12:09:24 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
	Point a(1, 3);
	Point b(1, 2);
	Point c(2, 3);
	Point p(1, 2);
	if (bsp(a, b, c, p))
		std::cout << "The Point is in the triangle" << std::endl;
	else
		std::cout << "The Point is no in the triangle" << std::endl;
	return (0);
}