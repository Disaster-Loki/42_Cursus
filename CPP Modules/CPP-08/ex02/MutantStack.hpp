#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <vector>

template <typename T>
class MutantStack{
    private:
        std::vector<T> v;
        unsigned int length;
    public:
        MutantStack();
        MutantStack(unsigned int len);
        ~MutantStack();
        MutantStack(const MutantStack &copy);
        MutantStack &operator=(const MutantStack &copy);
        void pop();
        unsigned int top();
        unsigned int size();
        void push(unsigned int value);
};

#include "MutantStack.tpp"

#endif