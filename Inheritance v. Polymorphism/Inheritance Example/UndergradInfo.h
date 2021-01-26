#ifndef UNDERGRADINFO_H
#define UNDERGRADINFO_H
#include "MortalInfo.h"

class UndergradInfo : public MortalInfo
{
public:
	//Constructors and Destructors
	UndergradInfo();
	UndergradInfo(std::string, std::string, std::string, std::string, std::string, std::string, std::string, int, bool);
	virtual ~UndergradInfo();

	//Mutator Functions
	void setUndergradNum(int);
	void setEnrolleeStatus(bool);

	//Accessor functions
	int getUndergradNum();
	bool isIncomingEnrollee();

	//Prints an object's information into input specified sized columns
	virtual void print(int, int, int, int, int, int, int, int, int);

private:
	int m_undergradNum;
	bool m_newEnrollee;
};

#endif // !UNDERGRADINFO_H