/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:28:28 by rbouquet          #+#    #+#             */
/*   Updated: 2025/03/28 16:09:11 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private:

		std::string	_name;
		Weapon		&_weapon;

	public:

		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		
		void	attack() const;

};

#endif