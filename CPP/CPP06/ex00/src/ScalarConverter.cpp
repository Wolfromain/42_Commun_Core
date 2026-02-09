/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:41:16 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/06 10:47:51 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	// std::cout << "ScalarConverter : Default constructor called " << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	// std::cout << "ScalarConverter : Destructor called " << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	// std::cout << "ScalarConverter : Copy constructor called " << std::endl;
	*this = cpy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &f)
{
	// std::cout << "ScalarConverter assignation operator called" << std::endl;
	if (this == &f)
		return (*this);
	return (*this);
}

bool ScalarConverter::isInt(const std::string& s)
{
	std::istringstream iss(s);
	int i;
	iss >> std::noskipws >> i;
	return iss.eof() && !iss.fail();
}

bool ScalarConverter::isFloat(const std::string& s)
{
	if (s.empty() || s[s.size() - 1] != 'f') return false;

	std::string noF = s.substr(0, s.size() - 1);
	std::istringstream iss(noF);
	float f;
	iss >> std::noskipws >> f;
	return iss.eof() && !iss.fail();
}

bool ScalarConverter::isDouble(const std::string& s)
{
	if (s.empty() || s[s.size() - 1] == 'f')
		return false;
	std::istringstream iss(s);
	double d;
	iss >> std::noskipws >> d;
	return iss.eof() && !iss.fail();
}

bool ScalarConverter::isSpecial(const std::string& s)
{
	return (s == "nan" || s == "nanf" || s == "+inf" || s == "+inff" ||
			s == "-inf" || s == "-inff");
}

Type detectType(const std::string& s)
{
	size_t  dot = s.find('.');
	size_t  f = s.find('f');
	if (dot == std::string::npos)
	{
		if (s.size() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]))
			return TYPE_CHAR;
		if (ScalarConverter::isSpecial(s))
			return TYPE_SPECIAL;
		if (ScalarConverter::isInt(s))
			return TYPE_INT;
	}
	bool dotFound = false;
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (s[i] == '.')
		{
			if (dotFound)
				return TYPE_INVALID;
			dotFound = true;
		}
	}
	if (f != std::string::npos && dot != std::string::npos && dot + 1 != f)
	{
		if (ScalarConverter::isFloat(s))
			return TYPE_FLOAT;
	}
	else if (f == std::string::npos && dot != std::string::npos)
		return TYPE_DOUBLE;
	return TYPE_INVALID;
}

void ScalarConverter::printChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::printInt(int i)
{
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f)
{
	std::cout << std::fixed << std::setprecision(1) 
			  << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
	std::cout << std::fixed << std::setprecision(1)
			  << "double: " << d << std::endl;
}

void ScalarConverter::printSpecial(const std::string &s)
{
	if (s == "nan" || s == "nanf")
	{
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: nanf" << std::endl
				  << "double: nan" << std::endl;
	}
	else if (s == "+inf" || s == "+inff")
	{
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: +inff" << std::endl
				  << "double: +inf" << std::endl;
	}
	else if (s == "-inf" || s == "-inff")
	{
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: -inff" << std::endl
				  << "double: -inf" << std::endl;
	}
	else
		std::cout << "Invalid special value." << std::endl;
}

void ScalarConverter::convert(const std::string &s)
{
	
	Type t = detectType(s);

	try
	{
		switch (t)
		{
			case TYPE_CHAR:
			{
				char c = s[0];
				printChar(c);
				printInt(static_cast<int>(c));
				printFloat(static_cast<float>(c));
				printDouble(static_cast<double>(c));
				break;
			}
			case TYPE_INT:
			{
				int i;
				std::istringstream iss(s);
				iss >> i;
				if (i < 0 || i > 127)
					std::cout << "char: impossible" << std::endl;
				else if (!std::isprint(i))
					std::cout << "char: Non displayable" << std::endl;
				else
					printChar(static_cast<char>(i));
				printInt(i);
				printFloat(static_cast<float>(i));
				printDouble(static_cast<double>(i));
				break;
			}
			case TYPE_FLOAT:
			{
				float f;
				std::istringstream iss(s.substr(0, s.size() - 1));
				iss >> f;
				if (f < 0 || f > 127)
					std::cout << "char: impossible" << std::endl;
				else if (!std::isprint(static_cast<int>(f)))
					std::cout << "char: Non displayable" << std::endl;
				else
					printChar(static_cast<char>(f));
				if (static_cast<long>(f) <= INT_MAX && static_cast<long>(f) >= INT_MIN)
					printInt(static_cast<int>(f));
				else
					std::cout << "int: impossible" << std::endl;
				printFloat(f);
				printDouble(static_cast<double>(f));
				break;
			}
			case TYPE_DOUBLE:
			{
				double d;
				std::istringstream iss(s);
				iss >> d;
				if (d < 0 || d > 127)
					std::cout << "char: impossible" << std::endl;
				else if (!std::isprint(static_cast<int>(d)))
					std::cout << "char: Non displayable" << std::endl;
				else
					printChar(static_cast<char>(d));
				if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
					std::cout << "int: impossible" << std::endl;
				else
					printInt(static_cast<int>(d));
				if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
					std::cout << "float: impossible" << std::endl;
				else
					printFloat(static_cast<float>(d));
				printDouble(d);
				break;
			}
			case TYPE_SPECIAL:
			{
				printSpecial(s);
				break;
			}
			default:
				std::cout << "Invalid input" << std::endl;
		}
	}
	catch (...)
	{
		std::cout << "Conversion error" << std::endl;
	}
}