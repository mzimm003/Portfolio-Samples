#ifndef CLERK_H
#define CLERK_H

#include "JobHolder.h"

class Clerk : public JobHolder
{
public:
	//Constructors and Destructor
	Clerk();
	Clerk(std::string name);
	virtual ~Clerk();

	//returns a short description of a JobHolder's duty
	virtual std::string jobDescription();
};

#endif //!CLERK_H