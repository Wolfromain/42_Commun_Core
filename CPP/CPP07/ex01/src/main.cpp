/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:43:46 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/11 11:43:07 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"

int main(void)
{
	const int Intarray[5] = {42, 134, 2, 5433, 838};
	std::string Stringarray[5] = {"Bonsoir", "a", "vous", "tous", "42"};
	float Floatarray[5] = {42.42, 6554.1, 9.235, 678.5, 0.0};

	std::cout << "IntArray :";
	::iter(Intarray, 5, printArray);

	std::cout << "\nStringArray :";
	::iter(Stringarray, 5, printArray);

	std::cout << "\nFloatArray :";
	::iter(Floatarray, 5, printArray);
	std::cout << std::endl;
}