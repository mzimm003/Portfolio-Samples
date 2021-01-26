//Mark Zimmerman
// Class assignment exampling use of STL
// (Revisions have been made to prevent identification of the specific assignment providing for potentially silly naming convention)
// Program reads C++ code and verifies characters requiring symmetry


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>

void displayCode(std::istream& file);
bool verifyFileSymmetry(std::istream& file);
void communicatePair(std::stack<int>& pairStackLine, std::stack<std::string>& pairStack, std::string open, std::string close);
void communicatePairFailure(int line, std::string open);
bool elementMatch(std::string opener, std::string closer);
std::string returnCloser(std::istream& context, char potentialCloser);
std::string uncertainCloser(std::istream& context, char potentialCloser);
std::string returnOpener(std::istream& context, char potentialOpener);
std::string uncertainOpener(std::istream& context, char potentialOpener);

int main() {
	std::string fileName;
	std::cout << "Please enter name of file to be compiled: ";
	std::cin >> fileName;

	std::ifstream infile(fileName);
	if (!infile) {
		std::cerr << "Error: cannot open " << fileName << "!" << std::endl;
		return -1;
	}

	displayCode(infile);
	verifyFileSymmetry(infile);

	return 0;
}

// Prints the file with preceding line numbers for each line.
void displayCode(std::istream& file) {
	std::string codeLine;
	int lineCount = 0;
	while (getline(file, codeLine)) {
		std::cout << std::setw(3) << std::left << ++lineCount << " " << codeLine << std::endl;
	}

	file.clear();
	file.seekg(0, file.beg);
}

// Takes a file and prints the matching code elements.
// Elements include: (), {}, [], "", '', /**/
// Characters within quotes or which are commented should not be considered
// Returns true if the file is balanced, false otherwise.
bool verifyFileSymmetry(std::istream& file) {
	// Parallel stacks to contain the opener char and the line from which it originates
	std::stack<std::string> elementOpeners;
	std::stack<int> elementOpenersLine;

	char codeChar;
	int lineCount = 1;
	bool balanced = true;

	while (file.get(codeChar) && balanced) {
	//check each character, store as an opener or closer character as approriate
		std::string openerChar = returnOpener(file, codeChar);
		std::string closerChar = returnCloser(file, codeChar);

		
		// Special instructions for certain characters in stack,
		// prevents considering other openers until a match or failure is found
		if (!elementOpeners.empty() && elementOpeners.top() == "//") {
			//if stack top == //, do nothing (for rest of line)
			if (codeChar == '\n') {
				elementOpeners.pop();
				elementOpenersLine.pop();
			}
		}
		else if (!elementOpeners.empty() && elementOpeners.top() == "/*") {
			//if stack top == /*, look for */ (until found)
			if (closerChar == "*/") {
				//if */ is found, pop stack
				communicatePair(elementOpenersLine, elementOpeners, elementOpeners.top(), closerChar);
			}
		}
		else if (!elementOpeners.empty() && (elementOpeners.top() == "\"" || elementOpeners.top() == "'")) {
			//if stack top == " or ', look for " or ' respectively
			if (codeChar == '\\') {
				//any character preceded by \ should be ignored
				file.get();
			}
			else if (elementMatch(elementOpeners.top(), closerChar)) {
				//if " or ' (as appropriate) is found, pop stack
				communicatePair(elementOpenersLine, elementOpeners, elementOpeners.top(), closerChar);
			}
		}
		//General instructions
		//if character is opener, push stack
		else if (openerChar.size() >= 1) {
			elementOpeners.push(openerChar);
			elementOpenersLine.push(lineCount);
		}
		//if character is closer matching stack top, pop stack
		else if (closerChar.size() >= 1) {
			if (!elementOpeners.empty() && elementMatch(elementOpeners.top(), closerChar)) {
				communicatePair(elementOpenersLine, elementOpeners, elementOpeners.top(), closerChar);
			}
			else {
				communicatePairFailure(lineCount, closerChar);
				balanced = false;
			}
		}
		
		if (codeChar == '\n') {
			// for elements which must be closed within the same line, fail upon newline
			if (!elementOpeners.empty() && (elementOpeners.top() == "\"" || elementOpeners.top() == "'")) {
				balanced = false;
			}
			lineCount++;
		}
	}

	if (!elementOpeners.empty()) {
		// "//" may still exist on stack if comment made on very last line
		if (elementOpeners.top() == "//") {
			elementOpeners.pop();
			elementOpenersLine.pop();
		}
		// Otherwise, if any elements still exist on the stack there's been a failure of pairing
		if (!elementOpeners.empty()) {
			communicatePairFailure(elementOpenersLine.top(), elementOpeners.top());
			balanced = false;
		}
	}
	return balanced;
}

void communicatePair(std::stack<int>& pairStackLine, std::stack<std::string>& pairStack, std::string open, std::string close) {
	std::cout << "pair matching " << open << " and " << close << std::endl;
	pairStack.pop();
	pairStackLine.pop();
}

void communicatePairFailure(int line, std::string open) {
	std::cout << "unbalanced " << open << " symbol on line " << line << std::endl;
}

//contains list of matches for openers and closers, returns whether given matches
bool elementMatch(std::string opener, std::string closer) {
	return opener == "/*" && closer == "*/" || 
		opener == "\"" && closer == "\"" ||
		opener == "'" && closer == "'" ||
		opener == "(" && closer == ")" ||
		opener == "{" && closer == "}" ||
		opener == "[" && closer == "]";
}

//returns the character given as a string if it qualifies as an closer, otherwise returns an empty string
std::string returnCloser(std::istream& context, char potentialCloser) {
	if (potentialCloser == '*') {
		return uncertainCloser(context, potentialCloser);
	}

	if (potentialCloser == '"' ||
		potentialCloser == '\'' ||
		potentialCloser == ')' ||
		potentialCloser == '}' ||
		potentialCloser == ']') {
		return std::string(1, potentialCloser);
	}

	return "";

}

// Differentiates pair of characters "*/" from other instances involving *
std::string uncertainCloser(std::istream& context, char potentialCloser) {
	char nextChar = context.peek();
	if (nextChar == '/') {
		context.get(); // consume "/" now accounted for
		return "*/";
	}
	else {
		return "";
	}
}

//returns the character given as a string if it qualifies as an opener, otherwise returns an empty string
std::string returnOpener(std::istream& context, char potentialOpener) {
	if (potentialOpener == '/') {
		return uncertainOpener(context, potentialOpener);
	}
	
	if (potentialOpener == '"' ||
		potentialOpener == '\'' ||
		potentialOpener == '(' ||
		potentialOpener == '{' ||
		potentialOpener == '[') {
		return std::string(1, potentialOpener);
	}

	return "";

}

// Differentiates pair of characters "/*" and "//" from other instances involving /
std::string uncertainOpener(std::istream& context, char potentialOpener) {
	char nextChar = context.peek();
	if (nextChar == '*') {
		context.get(); // consume "*" now accounted for
		return "/*";
	}
	else if (nextChar == '/') {
		context.get(); // consume "/" now accounted for
		return "//";
	}
	else {
		return "";
	}
}