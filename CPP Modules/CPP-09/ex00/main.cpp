/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:22:09 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/30 16:22:11 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <vector>

int main(int av, char **args)
{
    if (av <= 1){
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }
    std::string file = args[1];
    std::ifstream input (file.c_str());
    if (!input.is_open())
    {
        std::cout << "Error: Could not open file" << std::endl;
        return 1;
    }
    std::string line;
    std::vector<std::string> v;
    while (std::getline(input, line))
    {
        //std::cout << line << std::endl;
        v.push_back(line);
    }
    input.close();
    for (unsigned int i = 0; i < v.size(); i++)
        std::cout << v[i] << std::endl;
    std::cout << "Finished" << std::endl;
    return (0); 
}

