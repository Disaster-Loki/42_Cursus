/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:25:42 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/11 17:25:47 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        ~Point();
        Point(const Point &copy);
        Point(const float x, const float y);
        Point &operator=(const Point &y);
        Fixed getPoint_x()const ;
        Fixed getPoint_y() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif