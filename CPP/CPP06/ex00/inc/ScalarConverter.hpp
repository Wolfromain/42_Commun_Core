/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:41:00 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/28 17:49:21 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <sstream>
# include <cctype>
# include <limits>
# include <climits>
# include <cfloat>
# include <cmath>

enum Type {
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_INVALID,
	TYPE_SPECIAL
};

class ScalarConverter
{
	public :

		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &cpy);
		ScalarConverter &operator=(const ScalarConverter &f);

		static bool isInt(const std::string& s);
		static bool isFloat(const std::string& s);
		static bool isDouble(const std::string& s);
		static bool isSpecial(const std::string& s);

		static void printChar(char c);
		static void printInt(int i);
		static void printFloat(float f);
		static void printDouble(double d);
		static void printSpecial(const std::string &s);

		void convert(const std::string &s);
		
		
	private :

};

#endif