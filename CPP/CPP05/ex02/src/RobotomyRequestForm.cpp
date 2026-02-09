/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:52:04 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/19 09:30:59 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm : default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm : destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : _target(cpy._target)
{
	// std::cout << "RobotomyRequestForm : copy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	// std::cout << "RobotomyRequestForm : constructor called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &execute) const
{
	std::srand(std::time(0));
	if (this->getSigned() == false)
		throw AForm::FormNotSignException();
	else if (execute.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "Robot in activation... ⚠️" << std::endl;
	if (rand() % 2 == 0)
		std::cout << "RobotomyRequestForm : " << this->_target << " has been successfully robotomized " << std::endl;
	else
		std::cout << "RobotomyRequestForm : " << this->_target << " has failed to be robotomized" << std::endl;
}