/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:17:33 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/22 09:17:34 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void){
    std::vector<int> v;

    v.push_back(10);
    v.push_back(5);
    v.push_back(9);
    v.push_back(15);
    v.push_back(3);
    try{
        std::cout << ::easyfind(v, 12) << std::endl;
    }catch(std::runtime_error &e){
        std::cout << e.what() << std::endl;
    }
}