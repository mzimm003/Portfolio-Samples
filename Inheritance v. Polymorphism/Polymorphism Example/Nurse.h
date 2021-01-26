#ifndef NURSE_H
#define NURSE_H

#include "JobHolder.h"

class Nurse : public JobHolder
{
public:
	//Constructors and Destructor
	Nurse();
	Nurse(std::string name);
	virtual ~Nurse();
};

#endif //!NURSE_H