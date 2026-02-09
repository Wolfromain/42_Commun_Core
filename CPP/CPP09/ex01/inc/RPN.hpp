/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 10:13:49 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/25 13:52:47 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <string>
# include <cctype>

class RPN
{
	public:
		RPN();
		RPN(const RPN &cpy);
		RPN &operator=(const RPN &f);
		~RPN();

		void checkInput(const std::string &input);
		double calculateRPN(const std::string &calculInput);
		bool is_digit(char c)const;
};

#endif