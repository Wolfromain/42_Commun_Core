/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nezZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:42:09 by rbouquet          #+#    #+#             */
/*   Updated: 2025/03/25 10:45:10 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie	 *newZombie(std::string name)
{
	Zombie	*zombie = new Zombie(name);

	return (zombie);
}