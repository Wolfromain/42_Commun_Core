/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:42:45 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/21 16:16:53 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << "wrongCat : Default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat : Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cpy) : WrongAnimal()
{
	this->_type = cpy._type;
	std::cout << "WrongCat : Copy constuctor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &f)
{
	this->_type = f._type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong MEWOOO" << std::endl;
}