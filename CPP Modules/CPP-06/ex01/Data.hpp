#ifndef DATA_HPP
#define DATA_HPP

#include <string>

typedef struct Data {
    int id;
    const std::string name;

    Data(int id, const std::string& name) : id(id), name(name) {}
} Data;

#endif
