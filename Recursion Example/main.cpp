// Mark Zimmerman
// Class assignment exampling recursion (to a fault), also featuring quicksort and binary search
// (Revisions have been made to prevent identification of the specific assignment providing for potentially silly naming convention)
// Program collects anagrams of a given word, as validated by a given lexicon

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAXPRODUCTS   = 20;    // Max matches that can be found
const int MAXLEXWORDS = 30000; // Max words that can be read in

int fillLex(istream& lexfile, string lex[]);
int fillLexMax(istream& lexfile, string lex[], int maximumLex);
void sortLexicon(string lex[], int lexStart, int lexEnd);
int quicksortPartition(string lex[], int lexStart, int lexEnd, string pivot);
int quicksortStartIterator(string lex[], int lexStart, string pivot);
int quicksortEndIterator(string lex[], int lexEnd, string pivot);
int logCombos(string word, const string lex[], int size, string products[]);
int logCombosMax(string word, const string lex[], int size, string products[], int remainingProducts);
int anagramLoop(string word, const string lex[], int size, string products[], int loopCount, int remainingProducts);
void showProducts(const string products[], int size);
int avoidDuplicateEffort(string& word, string duplicatedLetter, int place);

int main()
{
    string products[MAXPRODUCTS];
    string lex[MAXLEXWORDS];
    ifstream lexfile;         // file containing the list of words
    int nwords;                // number of words read from lexicon
    string word;
    
    string lexicon = "words.txt"; //default file

    lexfile.open(lexicon);
    if (!lexfile) {
        cout << "File " << lexicon << " not found!" << endl;
        return (1);
    }
    
    nwords = fillLex(lexfile, lex);
    lexfile.close();
    
    cout << "Please enter a string for an anagram: ";
    getline(std::cin, word);

    int numMatches = logCombos(word, lex, nwords, products);
    if (!numMatches)
        cout << "No matches found" << endl;
    else
        showProducts(products, numMatches);

    cout << "Press any key to quit..." << endl;
    cin.get();

	return 0;
}


int fillLex(istream& lexfile, string lex[]) {
    if (!(lexfile >> lex[0])) {
        return 0;
    }
    else {
        int wordsLoaded = 1 + fillLexMax(lexfile, lex + 1, MAXLEXWORDS - 1);
        sortLexicon(lex, 0, wordsLoaded - 1);
        return wordsLoaded;
    }
}

int fillLexMax(istream& lexfile, string lex[], int maximumLex) {
    if (maximumLex < 1 || !(lexfile >> lex[0])) {
        return 0;
    }
    else {
        return 1 + fillLexMax(lexfile, lex + 1, maximumLex - 1);
    }
}

void sortLexicon(string lex[], int lexStart, int lexEnd) {
    if (lexStart >= lexEnd) {
        return;
    }

    int partitionIndex = quicksortPartition(lex, lexStart, lexEnd, lex[lexStart]);

    sortLexicon(lex, lexStart, partitionIndex);
    sortLexicon(lex, partitionIndex + 1, lexEnd);
}

int quicksortPartition(string lex[], int lexStart, int lexEnd, string pivot) {

    lexStart = quicksortStartIterator(lex, lexStart, pivot);
    lexEnd = quicksortEndIterator(lex, lexEnd, pivot);

    if (lexStart >= lexEnd) {
        return lexEnd;
    }

    string temp = lex[lexStart];
    lex[lexStart] = lex[lexEnd];
    lex[lexEnd] = temp;

    return quicksortPartition(lex, lexStart + 1, lexEnd - 1, pivot);
}

int quicksortStartIterator(string lex[], int lexStart, string pivot) {
    if (lex[lexStart] >= pivot) {
        return lexStart;
    }

    return quicksortStartIterator(lex, lexStart + 1, pivot);
}

int quicksortEndIterator(string lex[], int lexEnd, string pivot) {
    if (lex[lexEnd] <= pivot) {
        return lexEnd;
    }

    return quicksortEndIterator(lex, lexEnd - 1, pivot);
}

//Logs each combination of a given word as validated by the lexicon
int logCombos(string word, const string lex[], int size, string products[]) {
    //base case: there is no lexicon left, or no word left to anagram
    if (size == 0) {
        return 0;
    }

    if (word == "") { //ready to check anagram against lexicon (already contained in products[0])
        if (products[0] == lex[size / 2]) {
            return 1; //returning 1 will preserve entry in products array (in addition to providing for the count)
        }
        else if (products[0] < lex[size / 2]) {
            //search entire lexicon (sorting irrelevant), searching half at a time to keep stack size low
            return logCombos(word, lex, size / 2, products);
        }
        else{
            return logCombos(word, lex + size / 2 + 1, (size - 1) / 2, products);
        }
    }

    return logCombosMax(word, lex, size, products, MAXPRODUCTS);
}

//Limits logCombos to a particular number of products logged
int logCombosMax(string word, const string lex[], int size, string products[], int remainingProducts) {
    //base case: there is no lexicon left, or no word left to anagram
    if (size == 0) {
        return 0;
    }

    if (word == "") { //ready to check anagram against lexicon (already contained in products[0])
        if (products[0] == lex[size / 2]) {
            return 1; //returning 1 will preserve entry in products array (in addition to providing for the count)
        }
        else if (products[0] < lex[size / 2]) {
            //search entire lexicon (sorting irrelevant), searching half at a time to keep stack size low
            return logCombos(word, lex, size / 2, products);
        }
        else {
            return logCombos(word, lex + size / 2 + 1, (size - 1) / 2, products);
        }
    }

    return anagramLoop(word, lex, size, products, word.length(), remainingProducts);
}

int anagramLoop(string word, const string lex[], int size, string products[], int loopCount, int remainingProducts) {
    if (loopCount <= 0) {
        return 0;
    }
    if (remainingProducts == 0) {
        return 0;
    }

    //consider character from word as addition to anagram
    string temp = products[0];
    products[0] += word.substr(loopCount - 1, 1);

    //seek complete anagrams with adjusted character set (word)
    int productsFound = logCombosMax(word.substr(0, loopCount - 1) + word.substr(loopCount), lex, size, products, remainingProducts);
    remainingProducts -= productsFound;

    if (remainingProducts > 0) {
        //reset adjusted anagram to consider other characters appended from word
        products[productsFound] = temp;

        //rearrange word, and reduce loop count, so as to avoid considering a character already considered.
        loopCount -= (avoidDuplicateEffort(word, word.substr(loopCount - 1, 1), word.length()) - 1);

        //continue in loop, tracking products
        productsFound += anagramLoop(word, lex, size, products + productsFound, loopCount - 1, remainingProducts);
    }
    return productsFound;
}


void showProducts(const string products[], int size) {
    if (size == 0) {
        cout << "No matches found" << endl;
        return;
    }
    if (size == 1) {
        cout << "Matching word " << products[0] << endl;
        return;
    }
    cout << "Matching word " << products[0] << endl;
    showProducts(products + 1, size - 1);
}

//Arranges "word" such that all duplicated letters are reinserted to the end of the word.
//Function returns number of instances of letter found.
int avoidDuplicateEffort(string &word, string duplicatedLetter, int place) {
    if (place <= 0) {
        return 0;
    }

    if (word.substr(place - 1, 1) == duplicatedLetter) {
        word = word.substr(0, place - 1) + word.substr(place) + word.substr(place - 1, 1);
        return 1 + avoidDuplicateEffort(word, duplicatedLetter, place - 1);
    }

    return 0 + avoidDuplicateEffort(word, duplicatedLetter, place - 1);
}