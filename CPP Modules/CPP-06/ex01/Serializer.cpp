/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:42:37 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/15 11:42:39 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
    std::cout << "Serializer construtor called" << std::endl;
}

Serializer::~Serializer(){
    std::cout << "Serializer destrutor called" << std::endl;
}

Serializer::Serializer(const Serializer &copy){
    std::cout << "Serializer copy construtor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &copy) {
    std::cout << "Serializer copy assignment operator called" << std::endl;
    return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw){
    return (reinterpret_cast<Data*>(raw));
}
