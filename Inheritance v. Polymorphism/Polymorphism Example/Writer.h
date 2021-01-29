#ifndef WRITER_H
#define WRITER_H

#include "JobHolder.h"

class Writer : public JobHolder
{
public:
	//Constructors and Destructor
	Writer();
	Writer(std::string name);
	virtual ~Writer();

	//returns a short description of a JobHolder's duty
	virtual std::string jobDescription();
};

#endif //!WRITER_H