/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:24:23 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/12 10:24:28 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>
#define EPSILON 0.0001

float triangle_area(const Point A, const Point B, const Point C)
{
	float A1 = A.getPoint_x().toFloat();
	float A2 = A.getPoint_y().toFloat();
	float B1 = B.getPoint_x().toFloat();
	float B2 = B.getPoint_y().toFloat();
	float C1 = C.getPoint_x().toFloat();
	float C2 = C.getPoint_y().toFloat();

	float area = std::fabs((A1 * (B2 - C2) + B1 * (C2 - A2) + C1 * (A2 - B2)) / 2.0f);
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float A = triangle_area(a, b, c);
	float A1 = triangle_area(point, a, b);
	float A2 = triangle_area(point, b, c);
	float A3 = triangle_area(point, a, c);

	return (std::fabs(A - (A1 + A2 + A3)) < EPSILON);
}