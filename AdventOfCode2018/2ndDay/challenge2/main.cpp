#include <string>
#include <fstream>
#include <iostream>
#include <vector>

std::string equalLetters(std::string fileName) {
    std::fstream input(fileName);
    std::string line;
    std::string a;
    std::string b;
    std::string answer;
    std::vector<std::string> lines;

    while (!input.eof()) {
        std::getline(input, line);
        lines.push_back(line);
    }

    for (size_t i = 0; i < lines.size(); ++i) {
        int count = 0;
        a = lines[i];

        for (size_t j = i + 1; j < lines.size(); ++j) {
	    b = lines[j];
	    count = 0;

            for (size_t k = 0; k < a.size(); ++k) {
                if (a[k] != b[k])
		    ++count;
		if (count > 1)
		    break;
	    }
	    if (count == 1)
	        break;
        }
        if (count == 1)
	    break;
    }

    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == b[i])
            answer += a[i];
    }

    return answer;
}

int main(int argc, char** argv) {
    std::cout << "Found: " << equalLetters("input.txt") << std::endl;
}
