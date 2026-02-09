/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:52:05 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/16 11:43:01 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm() : _name("default"), _signed(false)
{
	// std::cout << "AForm : default constructor called" << std::endl;
	this->_gradeToExecute = 150;
	this->_gradeToSign = 150;
}

AForm::~AForm()
{
	// std::cout << "AForm : destructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	// std::cout << "AForm : constructor called" << std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	this->_signed = false;
}

AForm &AForm::operator=(const AForm &f)
{
	// std::cout << "AForm assignation operator called" << std::endl;
	if (this != &f)
	{
		this->_gradeToExecute = f._gradeToExecute;
		this->_name = f._name;
		this->_signed = f._signed;
		this->_gradeToSign = f._gradeToSign;
	}
	return (*this);
}

AForm::AForm(const AForm &cpy) : _name(cpy._name), _gradeToSign(cpy._gradeToSign)
{
	// std::cout << "AForm : copy constructor called" << std::endl;
	this->_gradeToExecute = cpy._gradeToExecute;
	this->_signed = cpy._signed;
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

std::string AForm::getName() const
{
	return (this->_name);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void AForm::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::FormNotSignException::what() const throw()
{
	return ("the form is not signed for execution");
}

std::ostream &operator<<(std::ostream &out, AForm const &AForm)
{
	out << AForm.getName() << ", Aform grade to sign " << AForm.getGradeToSign();
	std::cout << ", Aform grade to execute " << AForm.getGradeToExecute() << ", signed " << AForm.getSigned();
	return (out);
}