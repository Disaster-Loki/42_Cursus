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

Fixed::Fixed(): fixed_point(0)
{
	std::cout << "Default construtor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int construtor called" << std::endl;
	this->fixed_point = num << num_fract_bits;
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    if (num >= 0)
        this->fixed_point = (int)(num * (1 << num_fract_bits) + 0.5f);
    else
        this->fixed_point = (int)(num * (1 << num_fract_bits) - 0.5f);
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy construtor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->fixed_point = copy.fixed_point;
	return (*this);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point);
}

void Fixed::setRawBits(int const raw) { this->fixed_point = raw; }

float Fixed::toFloat(void) const
{
    return (float)this->fixed_point / (1 << num_fract_bits);
}

int Fixed::toInt(void) const
{
    return this->fixed_point >> num_fract_bits;
}


std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}
