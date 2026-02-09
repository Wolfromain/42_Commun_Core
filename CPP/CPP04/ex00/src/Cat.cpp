/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:27:24 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/21 15:32:34 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "Cat : Default constructor called" << std::endl;
}

Cat::Cat(const Cat &cpy) : Animal()
{
	this->_type = cpy._type;
	std::cout << "Cat : Copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat : Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &f)
{
	this->_type = f._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat : MEWOOO" << std::endl;
}