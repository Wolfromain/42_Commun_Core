/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:27:59 by rbouquet          #+#    #+#             */
/*   Updated: 2025/03/31 13:33:16 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Sed.hpp"

Sed::Sed(std::string filename, std::string s1, std::string s2): _filename(filename), _s1(s1), _s2(s2)
{
}

Sed::~Sed()
{
}

void	Sed::replace()
{
	std::ifstream	in(this->_filename.c_str());
	if (!in.is_open())
	{
		std::cout << "Can't open the filename." << std::endl;
		return ;
	}
	std::ofstream out(this->_filename.append(".replace").c_str());
	if (!out.is_open())
	{
		std::cout << "Can't open the new file." << std::endl;
		return ;
	}
	if (this->_s1.empty())
	{
		std::cout << "s1 is empty." << std::endl;
		return ;
	}
	std::string	line;
	while (std::getline(in, line))
	{
		size_t pos = 0;
		while ((pos = line.find(this->_s1, pos)) != std::string::npos)
		{
			line.erase(pos, this->_s1.length());
			line.insert(pos, this->_s2);
		}
		out << line;
		if (!in.eof())
			out << std::endl;
	}
}