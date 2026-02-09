/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:41:25 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/21 18:42:59 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain
{
	private:

		std::string	_ideas[100];
		
	public:

		Brain();
		Brain(const Brain &cpy);
		~Brain();
		Brain &operator=(const Brain &f);

		void	setIdea(int i, std::string idea);
		std::string	getIdea(int i) const;
};

#endif