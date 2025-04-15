#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <stdexcept>

Base * generate(void)
{
    int rand = std::rand() % 3;
    if (rand == 0) return (new A());
    else if (rand == 1) return (new B());
    else return (new C());
}

void identify(Base* p) {
    if (p == NULL) {
        std::cout << "Error: Null pointer!" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p))
        std::cout << "Type A object" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type B object" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type C object" << std::endl;
    else
        std::cout << "Unknown object type" << std::endl;
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "Type A object" << std::endl;
    } catch (std::bad_cast&) {
        try {
            dynamic_cast<B&>(p);
            std::cout << "Type B object" << std::endl;
        } catch (std::bad_cast&) {
            try {
                dynamic_cast<C&>(p);
                std::cout << "Type C object" << std::endl;
            } catch (std::bad_cast&) {
                std::cout << "Unknown object type" << std::endl;
            }
        }
    }
}
