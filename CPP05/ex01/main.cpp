#include <string>
#include <iostream>
#include <limits>
#include <assert.h>

#include "Bureaucrat.hpp"
#include "Form.hpp"

template<typename T>
T* create(std::string const& name, int grade)
{
	try
	{
		return new T(name, grade);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return NULL;
	}
}

int main()
{
	Bureacrat *e1, *e2, *e3;
	Bureacrat *a1, *a2, *a3;
	e1 = e2 = e3 = NULL;
	a1 = a2 = a3 = NULL;
	e1 = create<Bureacrat>("Bob", 151);
	e2 = create<Bureacrat>("James", 0);
	e3 = create<Bureacrat>("JHOOOOOOON SEEENAAA", -100);

	a1 = create<Bureacrat>("Putana", 150);
	a2 = create<Bureacrat>("Leha", 1);
	a3 = create<Bureacrat>("Anton", 75);
	assert(!e1 && !e2 && !e3);
	assert(a1 && a2 && a3);
	try { a1->downgrade(); }  catch (std::exception& e) { std::cerr << e.what() << std::endl; }
	try { a2->gradeRise(); }  catch (std::exception& e) { std::cerr << e.what() << std::endl; }
	a3->gradeRise();
	a3->downgrade();
	assert(a1->getGrade() == 150);
	assert(a2->getGrade() == 1);
	assert(a3->getGrade() == 75);
	std::cout << *a1 << std::endl;
	std::cout << *a2 << std::endl;
	std::cout << *a1 << std::endl;

	Form *f1, *f2;
	Form *fe1, *fe2;
	fe1 = create<Form>("Test form low", 151);
	fe2 = create<Form>("Test form high", 0);
	assert (!fe1 && !fe2);
	f1 = create<Form>("Constitution", 2);
	f2 = create<Form>("Lower form", 150);
	assert(f1 && f2);
	a2->singForm(*f1);
	a1->singForm(*f1);
	a1->singForm(*f2);
	a2->singForm(*f2);
}
