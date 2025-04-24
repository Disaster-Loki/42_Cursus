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
#include <algorithm>
#include <stdexcept>
#include <vector>

template <typename T>
int easyfind(const T &container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        return std::distance(container.begin(), it);
    throw std::runtime_error("Error 404: Not found!");
}

#endif