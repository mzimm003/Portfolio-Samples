#include "Writer.h"

Writer::Writer() : JobHolder("", 108080.00) {

}

Writer::Writer(std::string name) : JobHolder(name, 108080.00) {

}

Writer::~Writer() {

}

std::string Writer::jobDescription() {
	return "shares stories through text";
}