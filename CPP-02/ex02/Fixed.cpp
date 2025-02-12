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

#include "Fixed.hpp"

Fixed::Fixed(): fixed_point(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const int num)
{
	this->fixed_point = num << num_fract_bits;
}

Fixed::Fixed(const float num)
{
    if (num >= 0)
        this->fixed_point = (int)(num * (1 << num_fract_bits) + 0.5f);
    else
        this->fixed_point = (int)(num * (1 << num_fract_bits) - 0.5f);
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
		this->fixed_point = copy.fixed_point;
	return (*this);
}

int	Fixed::getRawBits() const
{
    return (this->fixed_point);
}

void Fixed::setRawBits(int const raw) { this->fixed_point = raw; }

float Fixed::toFloat(void) const
{
    return ((float)this->fixed_point / (1 << num_fract_bits));
}

int Fixed::toInt(void) const
{
    return (this->fixed_point >> num_fract_bits);
}

//Comparison operators
bool Fixed::operator>(const Fixed &fixed)
{
	return (this->fixed_point > fixed.fixed_point);
}

bool Fixed::operator<(const Fixed &fixed)
{
	return (this->fixed_point < fixed.fixed_point);
}

bool Fixed::operator>=(const Fixed &fixed)
{
	return (this->fixed_point >= fixed.fixed_point);
}

bool Fixed::operator<=(const Fixed &fixed)
{
	return (this->fixed_point <= fixed.fixed_point);
}

bool Fixed::operator==(const Fixed &fixed)
{
	return (this->fixed_point == fixed.fixed_point);
}

bool Fixed::operator!=(const Fixed &fixed)
{
	return (this->fixed_point != fixed.fixed_point);
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &fixed)
{
	Fixed tmp;
	tmp.fixed_point = this->fixed_point + fixed.fixed_point;
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	Fixed tmp;
	tmp.fixed_point = this->fixed_point - fixed.fixed_point;
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &fixed)
{
	Fixed tmp;
	tmp.fixed_point = (this->fixed_point * fixed.fixed_point) >> num_fract_bits;
	return (tmp);
}

Fixed Fixed::operator/(const Fixed &fixed)
{
	Fixed tmp;
	tmp.fixed_point = (this->fixed_point << num_fract_bits) / fixed.fixed_point;
	return (tmp);
}

// Increment/decrement operators

Fixed &Fixed::operator++()
{
	this->fixed_point += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->fixed_point += 1;
	return (tmp);
}

Fixed &Fixed::operator--()
{
	this->fixed_point -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->fixed_point -= 1;
	return (tmp);
}

// Static Functions
Fixed &Fixed::min(Fixed &one, Fixed &two)
{
	if (one.fixed_point >= two.fixed_point)
		return (two);
	return (one);
}

Fixed const &Fixed::min(const Fixed &one, const Fixed &two)
{
	if (one.fixed_point >= two.fixed_point)
		return (two);
	return (one);
}


Fixed &Fixed::max(Fixed &one, Fixed &two)
{
	if (one.fixed_point <= two.fixed_point)
		return (two);
	return (one);
}

Fixed const &Fixed::max(const Fixed &one, const Fixed &two)
{
	if (one.fixed_point <= two.fixed_point)
		return (two);
	return (one);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}
