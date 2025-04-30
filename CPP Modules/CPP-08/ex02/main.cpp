/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:01:16 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/24 13:01:18 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "--------- Teste base do subject -----------" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "--------- Teste extra 1: Copy and assignment -----------" << std::endl;
    MutantStack<int> copy(mstack);
    MutantStack<int> assigned;
    assigned = mstack;
    std::cout << "Copy top: " << copy.top() << std::endl;
    std::cout << "Assigned top: " << assigned.top() << std::endl;
    std::cout << "--------- Teste extra 2: Iterating copied stack -----------" << std::endl;
    for (MutantStack<int>::iterator cit = copy.begin(); cit != copy.end(); ++cit)
        std::cout << *cit << std::endl;
    std::cout << "--------- Teste extra 3: Empty stack test -----------" << std::endl;
    MutantStack<int> emptyStack;
    std::cout << "Is empty? " << (emptyStack.empty() ? "Yes" : "No") << std::endl;
    emptyStack.push(42);
    std::cout << "After push, empty? " << (emptyStack.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Top: " << emptyStack.top() << std::endl;
    emptyStack.pop();
    std::cout << "Empty after pop? " << (emptyStack.empty() ? "Yes" : "No") << std::endl;
    return 0;
}
