/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:03:02 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/11 15:47:24 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// std::cout << "Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	*this = cpy;
	_date = cpy._date;
	_value = cpy._value;
	// std::cout << "Copy constructor called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &f)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
	{
		_date = f._date;
		_value = f._value;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "Destructor called" << std::endl;
}

std::map<std::string, double> BitcoinExchange::readCSV(const std::string &filename)
{
	std::map<std::string, double> dataMap;
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open CSV file." << std::endl;
		return (dataMap);
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date, valueStr;
		if (!std::getline(iss, date, ',') || !std::getline(iss, valueStr))
		{
			std::cerr << "Error: Bad CSV format." << std::endl;
			continue;
		}
		date.erase(0, date.find_first_not_of(" \t\r\n"));
		date.erase(date.find_last_not_of(" \t\r\n") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t\r\n"));
		valueStr.erase(valueStr.find_last_not_of(" \t\r\n") + 1);

		double value;
		std::istringstream valueStream(valueStr);
		if (!(valueStream >> value))
		{
			std::cerr << "Error: Value is not a number in CSV." << std::endl;
			continue;
		}
		dataMap[date] = value;
	}
	file.close();
	return (dataMap);
}

double BitcoinExchange::getResult(const std::string &date, double value, const std::map<std::string, double> &dataMap)
{
	std::map<std::string, double>::const_iterator it = dataMap.lower_bound(date);
	if (it == dataMap.end())
	{
		std::cerr << "Error: No data available for date " << date << "." << std::endl;
		return (-1);
	}
	if (it->first != date && it != dataMap.begin())
		it--;

	double rate = it->second;
	return (value * rate);
}

void BitcoinExchange::parseInput(std::ifstream &input, const std::map<std::string, double> &dataMap)
{
	std::string line;
	bool firstLine = true;
	while (std::getline(input, line))
	{
		if (firstLine && (line.find("date") != std::string::npos && line.find("value") != std::string::npos))
		{
			firstLine = false;
			continue;
		}
		std::string::size_type sep = line.find('|');
		if (sep == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, sep);
		std::string valueStr = line.substr(sep + 1);
		date.erase(0, date.find_first_not_of(" \t\r\n"));
		date.erase(date.find_last_not_of(" \t\r\n") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t\r\n"));
		valueStr.erase(valueStr.find_last_not_of(" \t\r\n") + 1);

		std::istringstream iss(valueStr);
		double value;
		if (!(iss >> value) || !(iss.eof()))
		{
			std::cerr << "Error: Invalid value => " << valueStr << std::endl;
			continue;
		}
		if (!isValidDate(date))
		{
			std::cerr << "Error: Invalid date => " << date << std::endl;
			continue;
		}
		if (!isValidValue(value))
			continue;
		double result = getResult(date, value, dataMap);
		if (result != -1)
			std::cout << date << " => " << value << " = " << result << std::endl;
	}
}

bool	BitcoinExchange::isValidDate(std::string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	std::istringstream iss(date);
	int	year, month, day;
	int	MaxDaysMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char	dash1, dash2;
	
	if (!(iss >> year >> dash1 >> month >> dash2 >> day))
		return (false);
	if (year <= 2009 && month <= 1 && day < 2)
		return (false);
	if (month == 2)
	{
		bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (isLeap)
			MaxDaysMonth[1] = 29;
	}
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > MaxDaysMonth[month - 1])
		return (false);
	return (true);
}

bool BitcoinExchange::isValidValue(double value)
{
	if (value < 0)
	{
		std::cerr << "Error: Negative value." << std::endl;
		return (false);
	}
	if (value > 1000)
	{
		std::cerr << "Error: Value too large." << std::endl;
		return (false);
	}
	return (true);
}