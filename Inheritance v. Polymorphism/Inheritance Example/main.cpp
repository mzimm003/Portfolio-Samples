//Mark Zimmerman
//Class assignment exampling Inheritance
//(Revisions have been made to prevent identification of the specific assignment providing for potentially silly naming convention)
//The Incredibly Temporary Rolodex will take user input for various information about as many people as the user wishes to store.
//Ultimately, this information will be compiled and provided back to the user in a grid report

#include <iostream>
#include <iomanip>
#include "MortalInfo.h"
#include "UndergradInfo.h"

void fillRolodex(MortalInfo** rolodex, int rolodexSize);
void printRolodex(MortalInfo** rolodex, int rolodexSize);

int main() {
	//Get user input on number of people to store in rolodex
	int numOfPeople = -1;
	std::cout << "Welcome to the incredibly temporary Rolodex.\n";
	std::cout << "How many people would you like to keep track of (while this program is running):\n";

	//validate for countable number of persons
	while (numOfPeople < 1) {
		std::cin >> numOfPeople;
		if (numOfPeople < 1) {
			std::cout << "I'm not sure how to handle that many people. Please provide a standard counting number of people you would like to keep track of:\n";
		}
	}
	
	std::string temp; //to clear input stream
	std::getline(std::cin, temp);

	std::cout << "Excellent. We will now begin the entry process for your " << numOfPeople << " people.\n";

	MortalInfo** rolodex = new MortalInfo*[numOfPeople]; //Array to store MortalInfo and UndergradInfo objects

	fillRolodex(rolodex, numOfPeople);

	std::cout << "\nThank you!\n";

	printRolodex(rolodex, numOfPeople);

	//Deallocate memory
	for (int i = 0; i < numOfPeople; i++) {
		delete rolodex[i];
	}
	delete[] rolodex;
	return 0;
}

//Takes user input for each person in the rolodex
void fillRolodex(MortalInfo** rolodex, int rolodexSize) {
	for (int i = 0; i < rolodexSize; i++) {
		std::string initialName,
			finalName,
			houseLocation,
			municipality,
			commonwealth,
			zoneImprovementPlanID,
			contactNumber;
		int ID;
		bool newEnrollee = false;
		char isStudent = '\0',
			isFreshman = '\0';

		std::cout << "Entering information for person " << i + 1 << ":\n";
		std::cout << "First name: ";
		std::getline(std::cin, initialName);
		std::cout << "Last name: ";
		std::getline(std::cin, finalName);
		std::cout << "Street address: ";
		std::getline(std::cin, houseLocation);
		std::cout << "City: ";
		std::getline(std::cin, municipality);
		std::cout << "State: ";
		std::getline(std::cin, commonwealth);
		std::cout << "Zip code: ";
		std::getline(std::cin, zoneImprovementPlanID);
		std::cout << "Phone number: ";
		std::getline(std::cin, contactNumber);
		std::cout << "\nIs this person a student? (Y/N)\n";
		std::cin >> isStudent;

		std::string temp; //to clear input stream
		std::getline(std::cin, temp);

		if (isStudent == 'Y' || isStudent == 'y') {
			std::cout << "Please further provide the following information:\n";
			std::cout << "Student ID: ";
			std::cin >> ID;
			std::cout << "Is this person a new incoming Freshman? (Y/N): ";
			std::cin >> isFreshman;
						
			std::getline(std::cin, temp); //to clear input stream

			if (isFreshman == 'Y' || isFreshman == 'y') {
				newEnrollee = true;
			}
			rolodex[i] = new UndergradInfo(initialName, finalName, houseLocation, municipality, commonwealth, zoneImprovementPlanID, contactNumber, ID, newEnrollee);
		}
		else {
			rolodex[i] = new MortalInfo(initialName, finalName, houseLocation, municipality, commonwealth, zoneImprovementPlanID, contactNumber);
		}
		std::cout << std::endl;
	}
}

void printRolodex(MortalInfo** rolodex, int rolodexSize) {
	//Set information report column width parameters
	int reportCol1Size = 12,
		reportCol2Size = 15,
		reportCol3Size = 25,
		reportCol4Size = 12,
		reportCol5Size = 7,
		reportCol6Size = 10,
		reportCol7Size = 14,
		reportCol8Size = 12,
		reportCol9Size = 5;

	//Output information report
	std::cout << "\nHere is your rolodex:\n";
	//Headers
	std::cout << std::left << std::setw(reportCol1Size) << "First Name"
		<< std::left << std::setw(reportCol2Size) << "Last Name"
		<< std::left << std::setw(reportCol3Size) << "Address"
		<< std::left << std::setw(reportCol4Size) << "City"
		<< std::left << std::setw(reportCol5Size) << "State"
		<< std::left << std::setw(reportCol6Size) << "Zip Code"
		<< std::left << std::setw(reportCol7Size) << "Phone Number"
		<< std::left << std::setw(reportCol8Size) << "Student ID"
		<< std::left << std::setw(reportCol9Size) << "Incoming Freshman";
	std::cout << std::endl;
	//Rolodex content
	for (int i = 0; i < rolodexSize; i++) {
		rolodex[i]->print(reportCol1Size, reportCol2Size, reportCol3Size, reportCol4Size, reportCol5Size, reportCol6Size, reportCol7Size, reportCol8Size, reportCol9Size);
		std::cout << std::endl;
	}
}