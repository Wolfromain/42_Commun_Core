/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:14:26 by rbouquet          #+#    #+#             */
/*   Updated: 2025/03/28 15:46:15 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class Weapon
{
	private:

		std::string	_type;

	public:

		Weapon(std::string type);
		~Weapon();
		void			setType(std::string type);
		const std::string		&getType() ;

};

#endif