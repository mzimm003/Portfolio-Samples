#ifndef JOBHOLDER_H
#define JOBHOLDER_H

#include <string>

//Abstract Base Class
class JobHolder
{
public:
	//Constructors and Destructor
	JobHolder();
	JobHolder(std::string, double);
	virtual ~JobHolder();

	//Accessor functions
	std::string getName();
	double getSalary();

	//Mutator functions
	void setName(std::string);
	void setSalary(double);

	//returns a JobHolder's salary per week assuming 52 weeks in a year
	double salaryPerWeek();

	//returns a short description of a JobHolder's duty
	virtual std::string jobDescription() = 0;
private:
	std::string m_name;
	double m_salary;
};

#endif //!JOBHOLDER_H