/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:50:52 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/02 09:53:30 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main(int argc, char **argv)
{
	Harl	harl;
	
	if (argc != 2)
	{
		std::cout << "Wrong number of parameters. Try : ./Harl DEBUG/INFO/WARNING/ERROR." << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}