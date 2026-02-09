/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:03:38 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/18 10:59:48 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(2147483647);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		return (0);
	}
	
	// {
	// 	Span test = Span(5);
	// 	test.randomFill();
	// 	std::cout << test.shortestSpan() << std::endl;
	// 	std::cout << test.longestSpan() << std::endl;
	// }
}