/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:40:34 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/15 16:40:35 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <typename T>
class Array
{
    private:
        Array<T> array = new Array[];
    public:
        Array() { Array<T>[]; };
        ~Array();
        Array(unsigned int n) { Array<T>[n] = {0}; };
        Array(const Array<T> &copy) {};
        Array &operator=(const Array<T> &copy);
};

#endif
