/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:02:28 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/18 10:59:21 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <limits.h>
# include <algorithm>
# include <ctime>


class OutOfRange : public std::exception {
public:
	const char* what() const throw() {
		return ("Out of range");
	}
};

class Span
{
	public :

		Span(unsigned int n);
		Span(const Span &cpy);
		Span &operator=(const Span &f);
		~Span();

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;
		void randomFill();

	private :

		unsigned int _n;
		std::vector<int> _numbers;
};

#endif