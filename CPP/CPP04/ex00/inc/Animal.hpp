/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:46:05 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/21 15:34:24 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class Animal
{

	private:


	protected:

		std::string _type;

		
	public:

		Animal();
		Animal(const Animal &cpy);
		virtual ~Animal();
		Animal &operator=(const Animal &f);

		std::string	getType() const;
		virtual void	makeSound() const;

};

#endif