#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const& name, int grade)
	: m_name(name)
	, m_minSignGrade(grade)
	, m_isSigned(false)
{
	if (grade < 1)
		throw GradeTooHighException("grade is higher then maximum posible grade(1)");
	if (grade > 150)
		throw GradeTooLowException("grade is lower then minimum posible grade(150)");
}

Form::Form(Form const& other)
	: m_name(other.m_name)
	, m_minSignGrade(other.m_minSignGrade)
	, m_isSigned(other.m_isSigned) { }

Form& Form::operator = (Form const& other)
{
	m_name = other.m_name;
	m_isSigned = other.m_isSigned;
	m_minSignGrade = other.m_minSignGrade;
	return *this;
}

void Form::beSigned(Bureacrat const& other)
{
	if (other.getGrade() > m_minSignGrade)
		throw GradeTooLowException("bureacrat grade is too low to sign this form");
	m_isSigned = true;
}

bool Form::isSigned() const
{
	return m_isSigned;
}

std::string const& Form::getName() const
{
	return m_name;
}

int Form::minSignGrade() const
{
	return m_minSignGrade;
}
