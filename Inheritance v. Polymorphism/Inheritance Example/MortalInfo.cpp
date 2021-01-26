#include "MortalInfo.h"
#include <iostream>
#include <iomanip>

MortalInfo::MortalInfo(){ //Default constructor
	mem_finalName = "";
	mem_initialName = "";
	mem_houseLocation = "";
	mem_municipality = "";
	mem_commonwealth = "";
	mem_zoneImprovementPlanID = "";
	mem_contactNumber = "";
}

//Constructor with comprehensive input for object
MortalInfo::MortalInfo(std::string finalName,
						std::string initialName,
						std::string houseLocation,
						std::string municipality,
						std::string commonwealth,
						std::string zoneImprovementPlanID,
						std::string contactNumber){
	mem_finalName = finalName;
	mem_initialName = initialName;
	mem_houseLocation = houseLocation;
	mem_municipality = municipality;
	mem_commonwealth = commonwealth;
	mem_zoneImprovementPlanID = zoneImprovementPlanID;
	mem_contactNumber = contactNumber;
}

MortalInfo::~MortalInfo(){

}

void MortalInfo::setFinalName(std::string finalName){
	mem_finalName = finalName;
}

void MortalInfo::setInitialName(std::string initialName){
	mem_initialName = initialName;
}

void MortalInfo::setHouseLocation(std::string houseLocation){
	mem_houseLocation = houseLocation;
}

void MortalInfo::setMunicipality(std::string municipality){
	mem_municipality = municipality;
}

void MortalInfo::setCommonwealth(std::string commonwealth){
	mem_commonwealth = commonwealth;
}

void MortalInfo::setZoneImprovementPlanID(std::string zoneImprovementPlanID){
	mem_zoneImprovementPlanID = zoneImprovementPlanID;
}

void MortalInfo::setContactNumber(std::string contactNumber){
	mem_contactNumber = contactNumber;
}

std::string MortalInfo::getFinalName(){
	return mem_finalName;
}

std::string MortalInfo::getInitialName(){
	return mem_initialName;
}

std::string MortalInfo::getHouseLocation(){
	return mem_houseLocation;
}

std::string MortalInfo::getMunicipality(){
	return mem_municipality;
}

std::string MortalInfo::getCommonwealth() {
	return mem_commonwealth;
}

std::string MortalInfo::getZoneImprovementPlanID(){
	return mem_zoneImprovementPlanID;
}

std::string MortalInfo::getContactNumber(){
	return mem_contactNumber;
}

//Prints an object's information into input specified sized columns
//(8 and 9 are strictly to support sub-class print functions, this class has no information for these columns)
void MortalInfo::print(int col1size, int col2size, int col3size, int col4size, int col5size, int col6size, int col7size, int col8size, int col9size) {
	std::cout << std::left << std::setw(col1size) << mem_finalName
		<< std::left << std::setw(col2size) << mem_initialName
		<< std::left << std::setw(col3size) << mem_houseLocation
		<< std::left << std::setw(col4size) << mem_municipality
		<< std::left << std::setw(col5size) << mem_commonwealth
		<< std::left << std::setw(col6size) << mem_zoneImprovementPlanID
		<< std::left << std::setw(col7size) << mem_contactNumber;
}