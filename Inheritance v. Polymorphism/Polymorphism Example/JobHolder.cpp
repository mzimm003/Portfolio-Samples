#include "JobHolder.h"

JobHolder::JobHolder() {
	m_name = "";
	m_salary = 0;
}

JobHolder::JobHolder(std::string name, double salary) {
	m_name = name;
	m_salary = salary;
}

JobHolder::~JobHolder() {

}

//Accessor functions
std::string JobHolder::getName() {
	return m_name;
}

double JobHolder::getSalary() {
	return m_salary;
}

//Mutator functions
void JobHolder::setName(std::string name) {
	m_name = name;
}

void JobHolder::setSalary(double salary) {
	m_salary = salary;
}

//returns a JobHolder's salary per week assuming 52 weeks in a year
double JobHolder::salaryPerWeek() {
	return m_salary / 52;
}