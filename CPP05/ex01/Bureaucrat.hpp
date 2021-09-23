#pragma once

#include <stdexcept>
#include <iostream>

class Form;

class Bureacrat
{
public:
	Bureacrat(std::string const& name = "", int grade = 150);
	Bureacrat(Bureacrat const& o);
	Bureacrat& operator = (Bureacrat const& o);
	~Bureacrat();

	void gradeRise();
	void downgrade();

	void singForm(Form&) const;

	int                 getGrade() const { return m_grade; }
	std::string const&  getName() const { return m_name; }

	class GradeTooHighException : public std::logic_error
	{
	public: GradeTooHighException(std::string const& other);
	};

	class GradeTooLowException : public std::logic_error
	{
	public: GradeTooLowException(std::string const& other);
	};

private:
	std::string	m_name;
	int			m_grade;
};

inline std::ostream& operator << (std::ostream& os, Bureacrat const& bur)
{
	return os << bur.getName() << ", with grade " << bur.getGrade();
}
