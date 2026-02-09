/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:36:27 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/02 09:54:50 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl()
{
	this->ptr[0] = &Harl::_debug;
	this->ptr[1] = &Harl::_info;
	this->ptr[2] = &Harl::_warning;
	this->ptr[3] = &Harl::_error;
}

Harl::~Harl()
{
}

void	Harl::_debug()
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
	return ;
}

void	Harl::_info()
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Harl::_warning()
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
	return ;
}

void	Harl::_error()
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	int	i;
	std::string tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	i = 0;
	while (i < 4)
	{
		if (level == tab[i])
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			this->_debug();
			this->_info();
			this->_warning();
			this->_error();
			break;

		case 1:
			this->_info();
			this->_warning();
			this->_error();
			break;

		case 2:
			this->_warning();
			this->_error();
			break;

		case 3:
			this->_error();
			break;
		}
	return ;
}