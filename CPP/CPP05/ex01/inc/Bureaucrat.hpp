/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:26:07 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/16 11:07:26 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "../inc/Form.hpp"

class Form;

class Bureaucrat
{
	public	:

		Bureaucrat();
		Bureaucrat(const Bureaucrat &cpy);
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat	&operator=(const Bureaucrat &f);
		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(Form &form) const;
		
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
		int			_grade;

};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif