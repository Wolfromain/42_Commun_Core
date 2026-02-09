/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:13:27 by rbouquet          #+#    #+#             */
/*   Updated: 2025/03/31 14:10:41 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <fstream>

class	Sed
{
	private:

		std::string _filename;
		std::string _s1;
		std::string _s2;
		
	public:

		Sed(std::string filename, std::string s1, std::string s2);
		~Sed();
		void	replace();
};

#endif