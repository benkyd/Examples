#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// std::vector<std::string> parseFile(std::string fileName) {
//     std::cout << "test1" << fileName << std::endl;

//     std::vector<std::string> output;
//     std::cout << "test2" << fileName << std::endl;

//     std::fstream stream(fileName);
//     std::cout << "Reading: " << fileName << " into array" << std::endl;
    
//     for (std::string line; std::getline(stream, line); )
//         output.push_back(line);
//     return output;
// }

int main(int argc, char** argv) {
    try {
        std::cout << "WTF WHY ISNT THIS OUTPUTTING" << std::endl;

        std::vector<std::string> lines; // = parseFile("input.txt");// *(argv + 1));
        std::fstream stream("input.txt");

        // std::string line;
        // for (std::string line; std::getline(stream, line); ) {}
        //     lines.push_back(line);
        // for (unsigned int i = 0; i < lines.size(); i++)
        //     std::cout << lines[i] << std::endl;
    } catch (const std::string &e) {
        std::cout << e << std::endl;
    }
}
