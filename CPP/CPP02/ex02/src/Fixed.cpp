/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:30:33 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/28 09:46:06 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

const int Fixed::_static_number = 8;

Fixed::Fixed(): _fixed(0)
{
	return ;
}

Fixed::Fixed(const Fixed &cpy)
{
	*this = cpy;
	return ;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	if (this != &f)
		this->_fixed = f._fixed;
	return (*this);
}

Fixed::~Fixed()
{
	return ;
}

Fixed::Fixed(const int const_nbr)
{
	_fixed = const_nbr << _static_number;
}

Fixed::Fixed(const float flot_nbr)
{
	_fixed = roundf(flot_nbr * (1 << _static_number));
}

int Fixed::getRawBits(void) const
{
	return (this->_fixed);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

int Fixed::toInt( void ) const
{
	return (_fixed >> _static_number);
}

float Fixed::toFloat( void ) const
{
	return ((float)_fixed / (1 << _static_number));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}


bool	Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() !=fixed.toFloat());
}

Fixed	Fixed::operator+(Fixed fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(Fixed fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(Fixed fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(Fixed fixed) const
{
	if (fixed.toFloat() == 0)
	{
		std::cout << "Error: Division by zero" << std::endl;
		exit(1);
	}
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed	&Fixed::operator++()
{
	
	this->_fixed += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++*this;
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	this->_fixed--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--*this;
	return (tmp);
}

Fixed	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
