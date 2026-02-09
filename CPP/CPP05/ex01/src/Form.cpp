/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:52:05 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/06 10:05:53 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
	// std::cout << "Form : default constructor called" << std::endl;
}

Form::~Form()
{
	// std::cout << "Form : destructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	// std::cout << "Form : constructor called" << std::endl;
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw Form::GradeTooLowException();
	this->_signed = false;
}

Form &Form::operator=(const Form &f)
{
	// std::cout << "Form assignation operator called" << std::endl;
	if (this != &f)
	{
		this->_gradeToExecute = f._gradeToExecute;
		this->_name = f._name;
		this->_signed = f._signed;
		this->_gradeToSign = f._gradeToSign;
	}
	return (*this);
}

Form::Form(const Form &cpy) : _name(cpy._name), _gradeToSign(cpy._gradeToSign)
{
	// std::cout << "Form : copy constructor called" << std::endl;
	this->_gradeToExecute = cpy._gradeToExecute;
	this->_signed = cpy._signed;
}

bool Form::getSigned() const
{
	return (this->_signed);
}

std::string Form::getName() const
{
	return (this->_name);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, Form const &Form)
{
	out << Form.getName() << ", form grade to sign " << Form.getGradeToSign();
	std::cout << ", form grade to execute " << Form.getGradeToExecute() << ", signed " << Form.getSigned();
	return (out);
}