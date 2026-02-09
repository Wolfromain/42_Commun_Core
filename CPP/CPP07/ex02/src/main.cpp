/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:35:31 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/04 09:17:03 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

int main(void)
{
	Array<int> intArray(5);
	for (int i = 0; i < 5; ++i)
		intArray[i] = i * 10;

	std::cout << "Integer Array: ";
	intArray.printArray();

	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";

	std::cout << "String Array: ";
	strArray.printArray();

	try {
		std::cout << "Accessing out of bounds: " << intArray[10] << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}