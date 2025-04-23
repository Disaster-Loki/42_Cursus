#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include <iostream>

template <typename T>
MutantStack<T>::MutantStack() {
    std::cout << "MutantStack construtor called" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack() {
    std::cout << "MutantStack destrutor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) : std::stack<T>(copy) {
    std::cout << "MutantStack copy construtor called" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &copy) {
    if (this != &copy)
        std::stack<T>::operator=(copy);
    std::cout << "MutantStack copy assignment operator called" << std::endl;
    return *this;
}

template <typename T>
void MutantStack<T>::push(unsigned int value) {
    this->c.push_back(value);
    std::cout << "Value added successfully" << std::endl;
}

template <typename T>
void MutantStack<T>::pop() {
    this->c.pop_back();
    std::cout << "Pop successfully" << std::endl;
}

template <typename T>
unsigned int MutantStack<T>::top() {
    std::cout << "Value on top of MutantStack" << std::endl;
    return this->c.back();
}

template <typename T>
unsigned int MutantStack<T>::size() {
    return this->c.size();
}

template <typename T>
unsigned int MutantStack<T>::empty() {
    return this->c.empty() ? 1 : 0;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}

#endif
