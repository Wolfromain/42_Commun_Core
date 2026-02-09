/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:15:36 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/25 14:00:16 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main(int argc, char **argv)
{	
	if (argc < 3)
		std::cerr << "Error : Not enought arguments" << std::endl;
	else
	{
		PmergeMe<std::vector<int> > pmergeVector;
		PmergeMe<std::deque<int> > pmergeDeque;
		for (int i = 1; i < argc; i++)
		{
			long val = std::strtol(argv[i], NULL, 10);
			if (val < 0 || val > INT_MAX)
			{
				std::cerr << "Error : Only positif number is allow" << std::endl;
				return (1);
			}
			pmergeVector.add(std::atoi(argv[i]));
			pmergeDeque.add(std::atoi(argv[i]));
		}

		std::cout << "Before Vector container: ";
		for (std::vector<int>::const_iterator it = pmergeVector.getContainer().begin(); it != pmergeVector.getContainer().end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		// std::cout << "Before Deque container: ";
		// for (std::deque<int>::const_iterator it = pmergeDeque.getContainer().begin(); it != pmergeDeque.getContainer().end(); ++it)
		// 	std::cout << *it << " ";
		// std::cout << std::endl;
		
		clock_t start_vec = std::clock();
		algo(pmergeVector.getContainer());
		clock_t end_vec = std::clock();
		std::cout << std::endl;
		double elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;

		clock_t start_deq = std::clock();
		algo(pmergeDeque.getContainer());
		clock_t end_deq = std::clock();
		std::cout << std::endl;
		double elapsed_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC;
		
		std::cout << "After Vector container: ";
		for (std::vector<int>::const_iterator it = pmergeVector.getContainer().begin(); it != pmergeVector.getContainer().end(); ++it)
			std::cout << *it << " ";

		// std::cout << "After Deque container: ";
		// for (std::deque<int>::const_iterator it = pmergeDeque.getContainer().begin(); it != pmergeDeque.getContainer().end(); ++it)
		// 	std::cout << *it << " ";

		std::cout << std::endl;
		std::cout << "Time to process a range of " << pmergeVector.size() <<" elements with std::vector : " << elapsed_vec << " us" << std::endl;
		std::cout << "Time to process a range of " << pmergeDeque.size() <<" elements with std::deque : " << elapsed_deq << " us " << std::endl;
	}
}