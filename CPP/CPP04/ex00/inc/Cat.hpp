/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:41:00 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/21 15:41:49 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class	Cat: public Animal
{
	public:

		Cat();
		Cat(const Cat &cpy);
		~Cat();
		Cat &operator=(const Cat &f);

		void	makeSound() const;

};

#endif