/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:18:33 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/27 10:03:56 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int main(int argc, char* argv[])
{
	RPN rpn;
	int i = 0;
	if (argc != 2)
	{
		std::cerr << "Wrong input" << std::endl;
		return (1);
	}
	while (argv[1][i])
	{
		if (rpn.is_digit(argv[1][i]) || argv[1][i] == ' ' || argv[1][i] == '+' || argv[1][i] == '-' || argv[1][i] == '*' || argv[1][i] == '/')
			i++;
		else
		{
			std::cerr << "Wrong input" << std::endl;
			return (1);
		}
	}
	if (argc == 2)
		rpn.checkInput(argv[1]);
	else
		std::cerr << "Wrong input" << std::endl;
	return (0);
}
