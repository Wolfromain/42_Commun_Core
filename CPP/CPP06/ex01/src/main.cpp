/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:51:16 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/02 09:13:42 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serialize.hpp"
int main()
{
	Data data;
	data.value = 42;
	data.name = "Example";

	std::cout << "Original Data: " << data.value << ", " << data.name << std::endl;

	uintptr_t serializedData = Serialize::serialize(&data);
	std::cout << "Serialized Data: " << std::hex << serializedData << std::dec << std::endl;

	Data *deserializedData = Serialize::deserialize(serializedData);
	std::cout << "Deserialized Data: " << deserializedData->value << ", " << deserializedData->name << std::endl;

	return (0);
}