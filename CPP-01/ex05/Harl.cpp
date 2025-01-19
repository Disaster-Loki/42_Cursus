#include "Harl.hpp"

Harl::Harl() {}

void Harl::debug(void) {
    std::cout << "I love having extra bacon for my burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
}

void Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
}

void Harl::error(void) {
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
    for (int i = 0; i < 4; i++)
    {
        if (levers[i] == level)
        {
            (this->*functions[i])();
            return;
        }
    }
    std::cout << "Unknown level: " << level << std::endl;
}
