/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:17:46 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/22 09:17:48 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
int easyfind(const std::vector<T> &t, int x)
{
        int i = -1;
        while (++i < t.size())
        {
            if (t[i] == x)
                return (i);
        }
        throw std::runtime_error("Error 404: Not found!");
};

#endif