#include <iostream>
#include <fstream>
#include <string.h>

int main(int argc, char** argv) {
    if (argc != 2) return 0;

    std::fstream input;
    input.open(*(argv + 1));

    std::string polymerString;
    std::getline(input, polymerString);

    while (!false) {
        int numOfMods = 0;
        std::string eh = "";
        for (unsigned int i = 0; i < polymerString.length() - 1; i++) {
            if (islower((char)polymerString[i])) {
                if (toupper((char)polymerString[i]) == (char)polymerString[i+1]) {
                    eh += polymerString.substr(0, i);
                    eh += polymerString.substr(i + 2, polymerString.length());
                    numOfMods++;
                    break;
                }
            } 
            if (isupper((char)polymerString[i])) {
                if (tolower((char)polymerString[i]) == (char)polymerString[i+1]) {
                    eh += polymerString.substr(0, i);
                    eh += polymerString.substr(i + 2, polymerString.length());
                    numOfMods++;
                    break;
                }
            }
        }
        if (eh != "") {
            polymerString = eh;
        }
        std::cout << "Current length: " <<polymerString.length() << std::endl;
        if (numOfMods == 0) break;
    }
    std::cout << "Found polymers: " << polymerString << std::endl;
    std::cout << "At length: " << polymerString.length() << std::endl;
}
