/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:34:33 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/29 02:43:36 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serialize.hpp"

Serialize::Serialize()
{
	// std::cout << "Serialize : Default constructor called " << std::endl;
}

Serialize::~Serialize()
{
	// std::cout << "Serialize : Destructor called " << std::endl;
}

Serialize::Serialize(const Serialize &cpy)
{
	// std::cout << "Serialize : Copy constructor called " << std::endl;
	*this = cpy;
}

Serialize &Serialize::operator=(const Serialize &f)
{
	// std::cout << "Serialize assignation operator called" << std::endl;
	if (this == &f)
		return (*this);
	return (*this);
}

uintptr_t Serialize::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serialize::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
