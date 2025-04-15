/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:10:10 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/15 15:10:11 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>

template <typename T>
void swap(T& a, T& b) 
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T a, T b) { return (a < b ? a : b); }

template <typename T>
T max(T a, T b) { return (a > b ? a : b); }

#endif

