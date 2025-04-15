/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:07:59 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/15 12:08:01 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
#include <iostream>

class Base{
    public: virtual ~Base() = default; 
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
