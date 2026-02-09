/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:49:16 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/16 14:58:49 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	// std::cout << "Bureaucrat : default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	// std::cout << "Bureaucrat : constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name), _grade(cpy._grade)
{
	// std::cout << "Bureaucrat : copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Bureaucrat : destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &f)
{
	// std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &f)
		this->_grade = f._grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}
void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signAForm(AForm &Aform) const
{
	try
	{
		Aform.beSigned(*this);
		std::cout << this->getName() << " signed " << Aform.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " coulndn't sign " << Aform.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &Aform) const
{
	try
	{
		Aform.execute(*this);
		std::cout << this->getName() << " executed " << Aform.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " coulndn't execute " << Aform.getName() << " because " << e.what() << std::endl;
	}
}


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

