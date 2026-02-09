/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:31:54 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/19 16:18:54 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class FlagTrap : public ClapTrap
{

	private:

	public:
		
		FlagTrap();
		FlagTrap(std::string name);
		~FlagTrap();
		FlagTrap(const FlagTrap &cpy);
		FlagTrap &operator=	(const FlagTrap &f);

		void attack(const std::string& target);
		void highFivesGuys();
		
};

#endif