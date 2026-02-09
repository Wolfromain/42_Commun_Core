/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:34:38 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/29 02:55:14 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <stdint.h>

typedef struct Data
{
	int		value;
	std::string name;
}	Data;

class Serialize
{
	public:

		Serialize();
		~Serialize();
		Serialize(const Serialize &cpy);
		Serialize &operator=(const Serialize &f);

		static uintptr_t serialize(Data* ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif