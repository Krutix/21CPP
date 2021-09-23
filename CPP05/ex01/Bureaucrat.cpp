#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureacrat::Bureacrat(std::string const& name, int grade)
try
{
	if (grade < 1)
		throw GradeTooHighException(name + " grade is too high");
	if (grade > 150)
		throw GradeTooLowException(name + " grade is too low");
	m_name = name;
	m_grade = grade;
}
catch (std::exception& e) { throw ; }

Bureacrat::Bureacrat(Bureacrat const& o) : m_grade(o.m_grade) {}

Bureacrat& Bureacrat::operator = (Bureacrat const& o)
{
	if (&o == this)
		return *this;
	m_name = o.m_name;
	m_grade = o.m_grade;
	return *this;
}

Bureacrat::~Bureacrat() {}

void Bureacrat::gradeRise()
{
	if (m_grade - 1 < 1)
		throw GradeTooHighException(m_name + " grade rise is higher then max");
	m_grade--;
}

void Bureacrat::downgrade()
{
	if (m_grade + 1 > 150)
		throw GradeTooLowException(m_name + " downgrade is lower then min");
	m_grade++;
}

void Bureacrat::singForm(Form& form) const
{
	try {
		form.beSigned(*this);
		std::cout << *this << " signs " << form << std::endl;
	}
	catch (std::exception const& e) {
		std::cout << *this << " cannot sign " << form << " because " << e.what() << std::endl;
	}
}

Bureacrat::GradeTooHighException::GradeTooHighException(std::string const& other)
	: std::logic_error(other) {};

Bureacrat::GradeTooLowException::GradeTooLowException(std::string const& other)
	: std::logic_error(other) {};
