/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:10:41 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/27 09:29:41 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN()
{
	// std::cout << "Default constructor called" << std::endl;
}

RPN::RPN(const RPN &cpy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = cpy;
}

RPN &RPN::operator=(const RPN &f)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
	{
	}
	return *this;
}

RPN::~RPN()
{
	// std::cout << "Destructor called" << std::endl;
}

void RPN::checkInput(const std::string &input)
{
	try
	{
		double result = calculateRPN(input);
		std::cout << "Result: " << result << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

double RPN::calculateRPN(const std::string &calculInput)
{
	std::stack<double>		pile;
	std::istringstream	iss(calculInput);
	std::string			token;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			double	res = 0;
			if (pile.size() < 2)
				throw std::runtime_error("Insufficient values in stack for operation");
			double b = pile.top();
			pile.pop();
			double a = pile.top();
			pile.pop();
			if (token == "+")
				res = a + b;
			else if (token == "-")
				res = a - b;
			else if (token == "*")
				res = a * b;
			else if (token == "/")
			{
				if (b == 0)
					throw std::runtime_error("Division by 0 impossible");
				res = a / b;
			}
			pile.push(res);
		}
		else
		{
			if (token.length() != 1 || !is_digit(token[0]))
				throw std::runtime_error("Invalid token: only single digits allowed");
			pile.push(token[0] - '0');
		}
	}
	if (pile.size() != 1)
		throw std::runtime_error("Invalid RPN expression");
	return (pile.top());
}

bool RPN::is_digit(char c) const
{
	return (c >= '0' && c <= '9');
}