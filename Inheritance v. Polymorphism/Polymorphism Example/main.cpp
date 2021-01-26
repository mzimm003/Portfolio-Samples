//Mark Zimmerman
//Class assignment exampling polymorphism
//(Revisions have been made to prevent identification of the specific assignment providing for potentially silly naming convention)
//Program demonstrates the usefullness of polymorphism,
//printing unique results for each subclass of JobHolder from a single function

#include <iostream>
#include <iomanip>
#include "JobHolder.h"
#include "Nurse.h"
#include "Paralegal.h"
#include "Writer.h"
#include "Clerk.h"

void printSalary(JobHolder* person);

int main() {

	JobHolder* person1 = new Nurse("Mark");
	JobHolder* person2 = new Paralegal("Mike");
	JobHolder* person3 = new Writer("Mick");
	JobHolder* person4 = new Clerk("Mack");

	printSalary(person1);
	std::cout << std::endl;
	printSalary(person2);
	std::cout << std::endl;
	printSalary(person3);
	std::cout << std::endl;
	printSalary(person4);
	std::cout << std::endl;

	return 0;
}

void printSalary(JobHolder* person) {
	std::cout << std::fixed << std::setprecision(2) << person->getName() << " makes $" << person->getSalary() << " per year.\n";
	std::cout << "That's $" << person->salaryPerWeek() << " per week!\n";
}