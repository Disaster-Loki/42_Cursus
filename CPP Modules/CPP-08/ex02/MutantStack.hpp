#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        MutantStack();
        MutantStack(const MutantStack &copy);
        MutantStack &operator=(const MutantStack &copy);
        ~MutantStack();
        void push(unsigned int value);
        void pop();
        unsigned int top();
        unsigned int size();
        unsigned int empty();
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"

#endif
