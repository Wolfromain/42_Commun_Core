/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:14:59 by rbouquet          #+#    #+#             */
/*   Updated: 2025/03/25 12:05:42 by rbouquet         ###   ########.fr       */
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

		Zombie();
		~Zombie();
		void	zombieName(std::string str);
		void	announce();

};

Zombie* zombieHorde(int N, std::string name);

#endif