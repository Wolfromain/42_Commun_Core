/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:51:49 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/02 09:49:08 by rbouquet         ###   ########.fr       */
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
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
	return ;
}

void	Harl::_info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Harl::_warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
	return ;
}

void	Harl::_error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	int	i;
	std::string tab[4] = {"Debug", "Info", "Warning", "Error"};

	i = 0;
	while (i < 4)
	{
		if (level == tab[i])
		{
			(this->*ptr[i])();
			return ;
		}
		i++;
	}
	std::cout << "Error, wrong parameter." << std::endl;
	return ;
}