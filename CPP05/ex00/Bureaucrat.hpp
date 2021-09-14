#pragma once

#include <stdexcept>
#include <iostream>

typedef unsigned int uint32_t;

class Bureacrat
{
public:
	Bureacrat(std::string const& name = "", uint32_t grade = 150) throw(std::exception);

	Bureacrat(Bureacrat const& o);

	Bureacrat& operator = (Bureacrat const& o) throw(std::bad_alloc);

	~Bureacrat();

	void gradeRise() throw(Bureacrat::GradeTooHighException);

	void downgrade() throw(Bureacrat::GradeTooLowException);

	uint32_t            getGrade() const throw() { return m_grade; }
	std::string const&  getName() const throw() { return m_name; }

	class GradeTooHighException : public std::logic_error
	{
	public: GradeTooHighException(std::string const& other);
	};

	class GradeTooLowException : public std::logic_error
	{
	public: GradeTooLowException(std::string const& other);
	};

private:
	std::string m_name;
	uint32_t    m_grade;
};

inline std::ostream& operator << (std::ostream& os, Bureacrat const& bur)
{
	return os << bur.getName() << ", with grade " << bur.getGrade();
}
