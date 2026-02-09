/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:42:51 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/21 15:41:53 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class	Dog: public Animal
{
	public:

		Dog();
		Dog(const Dog &cpy);
		~Dog();
		Dog &operator=(const Dog &f);

		void	makeSound() const;

};

#endif