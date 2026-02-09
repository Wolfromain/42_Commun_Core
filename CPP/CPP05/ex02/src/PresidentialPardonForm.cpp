/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:22:03 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/19 09:30:27 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
	// std::cout << "PresidentialPardonForm : default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "PresidentialPardonForm : destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : _target(cpy._target)
{
	// std::cout << "PresidentialPardonForm : copy constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	// std::cout << "PresidentialPardonForm : constructor called" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &execute) const
{

	if (this->getSigned() == false)
		throw AForm::FormNotSignException();
	else if (execute.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "Presidential : " << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}