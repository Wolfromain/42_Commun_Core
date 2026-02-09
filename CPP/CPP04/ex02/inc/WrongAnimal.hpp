/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:40:38 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/22 13:57:34 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class WrongAnimal
{
	protected:
	
		std::string _type;

	public:

		WrongAnimal();
		WrongAnimal(const WrongAnimal &cpy);
		virtual ~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &f);

		std::string	getType() const;
		virtual void	makeSound() const;
};

#endif