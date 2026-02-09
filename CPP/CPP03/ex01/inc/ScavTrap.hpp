/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:44:12 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/19 16:15:27 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class ScavTrap : public ClapTrap
{

	private:

	public:
		
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(const ScavTrap &cpy);
		ScavTrap &operator=	(const ScavTrap &f);

		void guardGate();
		void attack(const std::string& target);
		
};

#endif