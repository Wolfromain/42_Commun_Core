/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:51:36 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/16 11:22:33 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public	:
	
		Form();
		Form(const Form &cpy);
		~Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form		&operator=(const Form &f);
		bool		getSigned() const;
		std::string	getName() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned(Bureaucrat bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public :
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public :
				const char *what() const throw();
		};

	private	:

		std::string	_name;
		bool		_signed;
		int			_gradeToSign;
		int			_gradeToExecute;


};

std::ostream &operator<<(std::ostream &out, Form const &Form);

#endif