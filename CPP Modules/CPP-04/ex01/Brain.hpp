/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:46:40 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 11:46:42 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
	    std::string ideas[100];
	public:
	    Brain();
	    Brain(const Brain& other);
	    Brain& operator=(const Brain& other);
	    ~Brain();
	    void setIdea(int index, const std::string& idea);
	    std::string getIdea(int index) const;
};

#endif
