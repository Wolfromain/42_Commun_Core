/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:43:20 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/02 15:19:18 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain : Default constructor called" << std::endl;
}

Brain::Brain(const Brain &cpy)
{
	std::cout << "Brain : Copy constructor called" << std::endl;
	*this = cpy;
}

Brain::~Brain()
{
	std::cout << "Brain : Destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &f)
{
	if (this != &f)
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = f._ideas[i];
	return (*this);
}

void	Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i >= 100)
	{
		std::cout << "Brain : Index out of range" << std::endl;
		std::cout << "Brain : Index must be between 0 and 99" << std::endl;
	}
	else
		this->_ideas[i] = idea;
}

std::string	Brain::getIdea(int i) const
{
	if (i < 0 || i > 100)
	{
		std::cout << "Brain : Index out of range" << std::endl;
		std::cout << "Brain : Index must be between 0 and 99" << std::endl;
	}
	else
		return (this->_ideas[i]);
	return ("");
}

