/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:21:24 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/02 09:41:46 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
# define HARL_CPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <fstream>

class	Harl
{
	private:

		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
		
	public:

	 	Harl();
		~Harl();
		void	(Harl::*ptr[4])();
		void	complain(std::string level);
};

#endif