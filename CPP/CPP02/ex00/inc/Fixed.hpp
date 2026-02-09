/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:46:11 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/02 12:34:16 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class Fixed
{
	private:

		int	_fixed;
		static const int _static_number;

	public:

		Fixed();
		~Fixed();
		Fixed(const Fixed &cpy);
		Fixed	&operator=(const Fixed &f);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif