// main.cpp
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
