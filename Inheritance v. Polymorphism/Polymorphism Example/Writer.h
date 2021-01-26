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
};

#endif //!WRITER_H