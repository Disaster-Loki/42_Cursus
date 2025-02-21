/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:25:21 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/11 17:25:26 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0) {}

Point::Point(const Point &copy): x(copy.x), y(copy.y) {}

Point::Point(float const x, float const y): x(Fixed(x)), y(Fixed(y)) {}

Point::~Point() {}

Fixed Point::getPoint_x() const { return (this->x); }

Fixed Point::getPoint_y() const { return (this->y); }
