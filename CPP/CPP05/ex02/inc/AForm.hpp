/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:51:36 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/16 11:22:33 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public	:
	
		AForm();
		AForm(const AForm &cpy);
		virtual ~AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm		&operator=(const AForm &f);
		bool		getSigned() const;
		std::string	getName() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned(Bureaucrat bureaucrat);
		virtual void execute(const Bureaucrat &execute) const = 0;

		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};

		class FormNotSignException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};

	private	:

		std::string	_name;
		bool		_signed;
		int			_gradeToSign;
		int			_gradeToExecute;


};

std::ostream &operator<<(std::ostream &out, AForm const &AForm);

#endif