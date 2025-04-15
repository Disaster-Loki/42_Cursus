/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:42:25 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/15 11:42:26 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main() {
    Data* original = new Data(42, "Luanda");

    uintptr_t raw = Serializer::serialize(original);

    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << original << std::endl;
    std::cout << "Restored pointer: " << restored << std::endl;

    std::cout << "Original data: " << original->id << ", " << original->name << std::endl;
    std::cout << "Restored data: " << restored->id << ", " << restored->name << std::endl;

    delete original;

    return 0;
}
