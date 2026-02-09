/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:42:51 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/22 13:57:37 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class	Dog: public Animal
{

	private:

		Brain	*_brain;

	public:

		Dog();
		Dog(const Dog &cpy);
		~Dog();
		Dog &operator=(const Dog &f);

		void	makeSound() const;
		Brain	*getBrain() const;

};

#endif