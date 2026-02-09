/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:02:27 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/17 15:56:20 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <cstdlib>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpy);
		BitcoinExchange &operator=(const BitcoinExchange &f);
		~BitcoinExchange();

		std::map<std::string, double> readCSV(const std::string &filename);
		double	getResult(const std::string &date, double value, const std::map<std::string, double> &dataMap);
		void	parseInput(std::ifstream &input, const std::map<std::string, double> &dataMap);
		bool	isValidDate(std::string &date);
		bool	isValidValue(double value);

	private:

		std::string _date;
		double _value;
};

#endif