/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:10:31 by rbouquet          #+#    #+#             */
/*   Updated: 2025/03/25 11:16:13 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
	
		Contact _contact[8];
		int		index;
		int		contact_nbr;

	public:

		PhoneBook();
		~PhoneBook();

		int		get_index();
		int		get_contact_nbr();
		int		set_contact(Contact contact);
		void	display(int i);
		int		display_all(int contact_index);
};

#endif