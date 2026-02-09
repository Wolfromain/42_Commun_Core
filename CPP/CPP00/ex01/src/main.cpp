/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 09:47:20 by rbouquet          #+#    #+#             */
/*   Updated: 2025/03/28 09:40:31 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

int	main(void)
{
	bool		isNumber;
	int			index;
	size_t		i;
	PhoneBook	pb;
	std::string	input;
	Contact		contact;

	isNumber = true;
	i = 0;
	index = 0;
	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT)" << std::endl;
		if (!(std::getline(std::cin, input)))
			return (1);
		if (!input.compare("EXIT"))
			return (0);
		else if (!input.compare("ADD"))
		{
			if (pb.set_contact(contact))
				return (0);
		}
		else if (!input.compare("SEARCH"))
		{
			if (pb.display_all(pb.get_contact_nbr()) == 0)
			{
				while (true)
				{
					i = 0;
					isNumber = true;
					std::cout << "Enter the index of the contact you want to display: ";
					if (!std::getline(std::cin, input))
						return (1);
					while (i < input.length())
					{
						if (!isdigit(input[i]))
							isNumber = false;
						i++;
					}
					index = std::atoi(input.c_str());
					if (isNumber && index >= 1 && index <= pb.get_contact_nbr())
					{
						pb.display(index - 1);
						break;
					}
					else
						std::cout << "Invalid index, please enter a number between 1 and " << pb.get_contact_nbr() << std::endl;
				}
			}		
		}
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}