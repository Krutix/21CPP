#include "Bureaucrat.hpp"

Bureacrat::Bureacrat(std::string const& name, uint32_t grade) throw(std::exception)
try
{
	if (grade < 1)
		throw GradeTooHighException("Grade is too high");
	if (grade > 150)
		throw GradeTooLowException("Grade is too low");
	m_name = name;
	m_grade = grade;
}
catch (std::exception& e) { throw ; }

Bureacrat::Bureacrat(Bureacrat const& o) : m_grade(o.m_grade) {}

Bureacrat& Bureacrat::operator = (Bureacrat const& o) throw(std::bad_alloc)
{
	if (&o == this)
		return *this;
	m_name = o.m_name;
	m_grade = o.m_grade;
	return *this;
}

Bureacrat::~Bureacrat() {}

void Bureacrat::gradeUp() throw(Bureacrat::GradeTooHighException)
{
	if (m_grade - 1 < 1)
		throw GradeTooHighException("Grade is too high");
	m_grade--;
}

void Bureacrat::gradeDown() throw(Bureacrat::GradeTooLowException)
{
	if (m_grade + 1 > 150)
		throw GradeTooLowException("Grade is too low");
	m_grade++;
}

Bureacrat::GradeTooHighException::GradeTooHighException(std::string const& other)
	: std::logic_error(other) {};

Bureacrat::GradeTooLowException::GradeTooLowException(std::string const& other)
	: std::logic_error(other) {};
