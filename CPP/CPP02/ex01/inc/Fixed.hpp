/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:30:16 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/02 14:40:46 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <cmath>

class Fixed
{
	private:

		int	_fixed;
		static const int _static_number;

	public:

		Fixed();
		Fixed(const int const_nbr);
		Fixed(const float flot_nbr);
		~Fixed();
		Fixed(const Fixed &cpy);
		Fixed	&operator=(const Fixed &f);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt( void ) const;
		float	toFloat( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif

