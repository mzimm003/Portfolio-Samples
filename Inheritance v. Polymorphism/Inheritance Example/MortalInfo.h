#ifndef MORTALINFO_H
#define MORTALINFO_H
#include <string>

class MortalInfo
{
public:
	//Constructors and Destructors
	MortalInfo();
	MortalInfo(std::string, std::string, std::string, std::string, std::string, std::string, std::string);
	virtual ~MortalInfo();

	//Mutator Functions
	void setFinalName(std::string);
	void setInitialName(std::string);
	void setHouseLocation(std::string);
	void setMunicipality(std::string);
	void setCommonwealth(std::string);
	void setZoneImprovementPlanID(std::string);
	void setContactNumber(std::string);

	//Accessor Functions
	std::string getFinalName();
	std::string getInitialName();
	std::string getHouseLocation();
	std::string getMunicipality();
	std::string getCommonwealth();
	std::string getZoneImprovementPlanID();
	std::string getContactNumber();

	//Prints an object's information into input specified sized columns
	virtual void print(int,int,int,int,int,int,int,int=0,int=0);

private:
	std::string mem_finalName,
				mem_initialName,
				mem_houseLocation,
				mem_municipality,
				mem_commonwealth,
				mem_zoneImprovementPlanID,
				mem_contactNumber;
};

#endif // !MORTALINFO_H