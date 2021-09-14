#include <string>
#include <iostream>
#include <limits>
#include <assert.h>

#include "Bureaucrat.hpp"

Bureacrat* createBureacrat(std::string const& name, uint32_t grade)
{
	try
	{
		return new Bureacrat(name, grade);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return NULL;
	}
	throw std::runtime_error("Unknown exception");
}

int main()
{
	Bureacrat *e1, *e2, *e3;
	Bureacrat *a1, *a2, *a3;
	e1 = e2 = e3 = NULL;
	a1 = a2 = a3 = NULL;
	e1 = createBureacrat("Bob", 151);
	e2 = createBureacrat("James", 0);
	e3 = createBureacrat("JHOOOOOOON SEEENAAA", -100);

	a1 = createBureacrat("Putana", 150);
	a2 = createBureacrat("Leha", 1);
	a3 = createBureacrat("Anton", 75);
	assert(!e1 && !e2 && !e3);
	assert(a1 && a2 && a3);
	try { a1->gradeDown(); }  catch (std::exception& e) { std::cerr << e.what() << std::endl; }
	try { a2->gradeUp(); }    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
	a3->gradeUp();
	a3->gradeDown();
	assert(a1->getGrade() == 150);
	assert(a2->getGrade() == 1);
	assert(a3->getGrade() == 75);
}
