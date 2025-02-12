/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:25:38 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/18 14:30:32 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

void Harl::debug() {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    std::string levers[] = {"DEBUG", "INFO", "WARNING","ERROR"};
    void (Harl::*functions[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    int index = -1;
    for (int i = 0; i < 4; i++)
    {
        if (levers[i] == level)
        {
            index = i; break;
        }
    }
    switch (index)
    {
        case 0: (this->*functions[0])(); (this->*functions[1])(); (this->*functions[2])();  (this->*functions[3])(); break;
        case 1: (this->*functions[1])(); (this->*functions[2])(); (this->*functions[3])(); break;
        case 2: (this->*functions[2])(); (this->*functions[3])(); break;
        case 3: (this->*functions[3])(); break;
        default: std::cout << "[ Probably complaining about insignificant problems ] " << std::endl;
    }
}
