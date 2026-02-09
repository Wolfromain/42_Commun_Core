/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:31:05 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/18 10:55:58 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"

int main()
{
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i)
	vec.push_back(i);
	
	try 
	{
		easyfind(vec, 3);
		std::cout << "Value found in the vector." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}