/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:51:54 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/28 10:45:21 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;

	std::cout << "\nb = " << b << std::endl;
	std::cout << "b = " << Fixed::max(a, b) << std::endl;

	return 0;
}