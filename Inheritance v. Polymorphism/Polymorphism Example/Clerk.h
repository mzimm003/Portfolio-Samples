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
};

#endif //!CLERK_H