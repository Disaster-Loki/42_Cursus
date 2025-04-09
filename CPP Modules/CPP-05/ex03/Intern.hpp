/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:18:40 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/09 18:18:42 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Intern
{
    private:
    public:
        Intern();
        ~Intern();
        Intern(const Intern &copy);
        Intern &operator=(const Intern &copy);
        AForm* makeForm(const std::string &name, const std::string &target);
};

#endif