/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:39:14 by rbouquet          #+#    #+#             */
/*   Updated: 2025/03/25 09:40:56 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	contact_nbr = 0;
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

int	PhoneBook::get_index()
{
	return (index);
}

int	PhoneBook::get_contact_nbr()
{
	return (contact_nbr);
}

int	PhoneBook::set_contact(Contact contact)
{
	if (index >= 8)
		index = 0;
	_contact[index] = contact;
	if (_contact[index].Add_Contact())
		return (1);
	index++;
	if (contact_nbr < 8)
		contact_nbr++;
	return (0);
}

void	PhoneBook::display(int i)
{
	_contact[i].Show_Contact();
}

int	PhoneBook::display_all(int contact_nbr)
{
	int	i;

	i = 0;
	if (contact_nbr == 0)
	{
		std::cout << "No contact in the PhoneBook" << std::endl;
		return (1);
	}
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	while (i < contact_nbr)
	{
		_contact[i].List_Contact(i);
		i++;
	}
	return (0);
}