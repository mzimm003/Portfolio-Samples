#include "UndergradInfo.h"
#include <iostream>
#include <iomanip>

UndergradInfo::UndergradInfo() : MortalInfo(){ //Default constructor
	m_undergradNum = -1;
	m_newEnrollee = false;
}

UndergradInfo::UndergradInfo(std::string finalName,  //Constructor with comprehensive input for object (utilizes base class constructor)
						std::string initialName,
						std::string houseLocation,
						std::string municipality,
						std::string commonwealth,
						std::string zoneImprovementPlanID,
						std::string contactNumber,
						int undergradNum,
						bool newEnrollee) : MortalInfo(finalName, initialName, houseLocation, municipality, commonwealth, zoneImprovementPlanID, contactNumber){
	m_undergradNum = undergradNum;
	m_newEnrollee = newEnrollee;
}

UndergradInfo::~UndergradInfo(){ //Destructor

}

void UndergradInfo::setUndergradNum(int undergradNum){
	m_undergradNum = undergradNum;
}

void UndergradInfo::setEnrolleeStatus(bool newEnrollee){
	m_newEnrollee = newEnrollee;
}

int UndergradInfo::getUndergradNum(){
	return m_undergradNum;
}

bool UndergradInfo::isIncomingEnrollee(){
	return m_newEnrollee;
}

//Prints an object's information into input specified sized columns (utilizes base class print function)
void UndergradInfo::print(int col1size, int col2size, int col3size, int col4size, int col5size, int col6size, int col7size, int col8size, int col9size) {
	//Print base class information
	MortalInfo::print(col1size,  col2size,  col3size,  col4size,  col5size,  col6size,  col7size);
	//Print class specific information
	std::cout << std::left << std::setw(col8size) << m_undergradNum;
	if (m_newEnrollee) {
		std::cout << std::left << std::setw(col9size) << "yes";
	}
}