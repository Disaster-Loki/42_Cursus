/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:18:11 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/15 16:18:13 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void print_arrays(const int &n){ std::cout << n << std::endl;}

int main(void){
    int array[5] = {1, 2, 3, 4, 5};
    ::iter(array, 5, print_arrays);
    return (0);
}