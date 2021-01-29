#include "Nurse.h"

Nurse::Nurse() : JobHolder("", 294000.00) {

}

Nurse::Nurse(std::string name) : JobHolder(name, 294000.00) {

}

Nurse::~Nurse() {

}

std::string Nurse::jobDescription() {
	return "cares for the sick";
}