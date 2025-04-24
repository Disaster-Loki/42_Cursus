/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:01:08 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/24 13:01:10 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        using iterator = typename std::stack<T>::container_type::iterator;
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
