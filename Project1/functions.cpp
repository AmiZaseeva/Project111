#include "header.h"

void removeSpaces(string& str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
}

void processLine(string& line, ofstream& outFile) {
    removeSpaces(line); 
    outFile << line << endl;
}