#include <string>
#include <iostream>
#include <fstream>

bool isRepeat(std::string line, int repeats) {
    for (char c = 'a'; c <= 'z'; ++c) {
        int count = 0;
        for (size_t i = 0; i < line.size(); ++i) {
	    if (line[i] == c)
                ++count;
        }
	if (count == repeats)
	    return true;
    }
    return false;
}

int checkSum(std::string fileName) {
    std::fstream input(fileName);
    std::string line;
    int doubles = 0;
    int triples = 0;
	
    while (!input.eof()) {
        std::getline(input, line);
        if (isRepeat(line, 2))
            ++doubles;
        if (isRepeat(line, 3))
            ++triples;
    }
    return doubles * triples;
}

int main(int argc, char** argv) {
    std::cout << "Found: " << checkSum("input.txt") << std::endl;
}
