/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:20:29 by rbouquet          #+#    #+#             */
/*   Updated: 2025/03/25 11:16:04 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class Contact
{
	private:

		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		std::string		phone_number;
		std::string		darkest_secret;

	public:
	
		Contact();
		~Contact();

		void setFirstName(const std::string &fn) { first_name = fn; }
		void setLastName(const std::string &ln) { last_name = ln; }
		void setNickname(const std::string &nn) { nickname = nn; }
		void setPhoneNumber(const std::string &pn) { phone_number = pn; }
		void setSecret(const std::string &ds) { darkest_secret = ds; }

		int		Add_Contact();
		void	List_Contact(int i);
		void	Show_Contact();
};

#endif