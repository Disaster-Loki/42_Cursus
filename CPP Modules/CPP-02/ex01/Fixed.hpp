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

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
	private:
		int	fixed_point;
		static const int num_fract_bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		int	getRawBits( void ) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif