/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:27:44 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/02 15:27:40 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Brain.hpp"

int main()
{
	// const Animal *animal = new Animal();
	// animal->makeSound();
	// delete animal;

	const Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();
	std::cout << std::endl;
	
	for (int i=0; i < 4; i++)
		animals[i]->makeSound();
	std::cout << std::endl;

	Dog	dog1;
	dog1.getBrain()->setIdea(0, "i could bark at this tree");
	std::cout << "dog1 idea 0 : " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog1 idea 1 : " << dog1.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;

	Cat	cat1;
	cat1.getBrain()->setIdea(0, "i could be the cutest creature on earth");
	std::cout << "cat1 idea 0 : " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "cat1 idea 1 : " << cat1.getBrain()->getIdea(1) << std::endl;
	std::cout << std::endl;

	for (int i=0; i < 4; i++)
		delete animals[i];

	return 0;
}