/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:56:54 by rbouquet          #+#    #+#             */
/*   Updated: 2025/03/25 12:05:56 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class Zombie
{
	private:

		std::string		name;

	public:

		Zombie(std::string str);
		~Zombie();
		void	announce();

};

Zombie	 *newZombie(std::string name);
void	randomChump(std::string name);

#endif