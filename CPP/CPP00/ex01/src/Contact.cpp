/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:39:02 by rbouquet          #+#    #+#             */
/*   Updated: 2025/03/25 10:55:45 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}

int Contact::Add_Contact()
{
	std::string input;

	std::cout << "First Name : ";
	while (input.empty())
	{
		if (!(std::getline(std::cin, input)))
			return (1);
	}
	setFirstName(input);
	input.clear();

	std::cout << "Last Name : ";
	while (input.empty())
	{
		if (!(std::getline(std::cin, input)))
			return (1);
	}
	setLastName(input);
	input.clear();

	std::cout << "Nick Name : ";
	while (input.empty())
	{
		if (!(std::getline(std::cin, input)))
			return (1);
	}
	setNickname(input);
	input.clear();

	std::cout << "Phone Number : ";
	while (input.empty())
	{
		if (!(std::getline(std::cin, input)))
			return (1);
	}
	setPhoneNumber(input);
	input.clear();

	std::cout << "Darkest Secret : ";
	while (input.empty())
	{
		if (!(std::getline(std::cin, input)))
			return (1);
	}
	setSecret(input);
	input.clear();
	return (0);
}

void Contact::List_Contact(int i)
{
	std::cout << "|" << std::setw(10) << std::right << i + 1 << "|";
	if (first_name.size() > 10)
		std::cout << std::setw(10) << std::right << first_name.substr(0, 9) + "." << "|";
	else
		std::cout << std::setw(10) << std::right << first_name << "|";
	if (last_name.size() > 10)
		std::cout << std::setw(10) << std::right << last_name.substr(0, 9) + "." << "|";
	else
		std::cout << std::setw(10) << std::right << last_name << "|";
	if (nickname.size() > 10)
		std::cout << std::setw(10) << std::right << nickname.substr(0, 9) + "." << "|";
	else
		std::cout << std::setw(10) << std::right << nickname << "|";
	std::cout << std::endl;
}

void	Contact::Show_Contact()
{
	std::cout << first_name << std::endl;
	std::cout << last_name << std::endl;
	std::cout << nickname << std::endl;
	std::cout << phone_number << std::endl;
	std::cout << darkest_secret << std::endl;
}