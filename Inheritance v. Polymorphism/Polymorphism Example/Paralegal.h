#ifndef PARALEGAL_H
#define PARALEGAL_H

#include "JobHolder.h"

class Paralegal : public JobHolder
{
public:
	//Constructors and Destructor
	Paralegal();
	Paralegal(std::string name);
	virtual ~Paralegal();
};

#endif //!PARALEGAL_H