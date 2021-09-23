#pragma once

#include <string>
#include <stdexcept>
#include <ostream>

class Bureacrat;

class Form
{
public:
	Form(std::string const& name, int grade = 150);
	Form(Form const&);
	Form& operator = (Form const&);

	void beSigned(Bureacrat const&);

	bool isSigned() const;
	std::string const& getName() const;
	int minSignGrade() const;

	class GradeTooHighException : public std::logic_error
	{
	public: GradeTooHighException(std::string const& msg) : std::logic_error(msg) {}
	};

	class GradeTooLowException : public std::logic_error
	{
	public: GradeTooLowException(std::string const& msg) : std::logic_error(msg) {}
	};

private:
	std::string	m_name;
	int			m_minSignGrade;
	bool		m_isSigned;
};

inline std::ostream& operator << (std::ostream& os, Form const& form)
{
	return os << form.getName() << "[" << form.minSignGrade() << (form.isSigned() ? ":signed" : "") << "]";
}
