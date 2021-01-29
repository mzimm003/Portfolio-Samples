#include "Clerk.h"

Clerk::Clerk() : JobHolder("", 64310.00) {

}

Clerk::Clerk(std::string name) : JobHolder(name, 64310.00) {

}

Clerk::~Clerk() {

}

std::string Clerk::jobDescription() {
	return "keeps records for a government agency";
}