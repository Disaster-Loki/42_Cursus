/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:25:38 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/18 14:30:32 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replace_occur(const std::string &line, const std::string &s1, const std::string &s2)
{
    if (s1.empty())
        return line;

    std::string result = line;
    std::string::size_type pos = 0;
    std::cout << "npos: " << std::string::npos << std::endl;
    while ((pos = result.find(s1, pos)) != std::string::npos)
    {
        result.erase(pos, s1.length());
        result.insert(pos, s2);
        pos += s2.length();
    }
    return result;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream input(filename.c_str());
    if (!input.is_open())
    {
        std::cout << "Error: Could not open file" << std::endl;
        return 1;
    }

    std::ofstream output((filename + ".replace").c_str());
    if (!output.is_open())
    {
        std::cout << "Error: Could not create file" << std::endl;
        input.close();
        return 1;
    }

    std::string line;
    while (std::getline(input, line))
    {
        output << replace_occur(line, s1, s2) << std::endl;
    }

    input.close();
    output.close();
    std::cout << "Successful" << std::endl;
    return 0;
}
