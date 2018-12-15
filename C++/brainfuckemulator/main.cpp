#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

// > 	Increment the pointer.
// < 	Decrement the pointer.
// + 	Increment the byte at the pointer.
// - 	Decrement the byte at the pointer.
// . 	Output the byte at the pointer.
// , 	Input a byte and store it in the byte at the pointer.
// [ 	Jump forward past the matching ] if the byte at the pointer is zero.
// ] 	Jump backward to the matching [ unless the byte at the pointer is zero.

class BrainFuck {
public:
    char stack[30000];
    int programCounter = 0;
    char* ptr;
    std::string program;

    BrainFuck(std::string program) {
        this->program = program;
        this->ptr = (char*)this->program.c_str();
    }

    bool tick() {
        if (programCounter >= 30000) return false;
        int bal;
        switch((char)program[programCounter]) {
            case '>': ++ptr; break;
            case '<': --ptr; break;
            case '+': ++*ptr; break;
            case '-': --*ptr; break;
            case '.': programPrint(*ptr); break;
            case ',': break; // TODO GETS();
            case '[':   
                        bal = 1;
                        if (*ptr == '\0') {
                            do {
                                programCounter++;
                                if (program[programCounter] == '[') bal++;
                                else if (program[programCounter] == ']') bal--;
                            } while (bal != 0);
                        }
                        break;
            case ']':
                        bal = 0;
                        do {
                            if (program[programCounter] == '[') bal++;
                            else if (program[programCounter] == ']') bal--;
                            programCounter--;
                        } while (bal != 0);
                        break;
        }
        programCounter++;
        return true;
    }

    void programPrint(char toPrint) {
        std::cout << "OUTPUT AT POSITION " << programCounter << ": ";
        putchar(toPrint);
        putchar('\n');
    }
};

int main(int argc, char** argv) {
    if (argc < 2) {std::cout << "No input file specified" << std::endl; exit(0); }
    
    std::ifstream input(*(argv + 1));
    std::string programStream;

    for (std::string line; std::getline(input, line); )
        programStream += line;

    programStream.erase(std::remove(programStream.begin(), programStream.end(), '\n'), programStream.end());

    BrainFuck CPU(programStream);

    while (1) {
        if (!CPU.tick()) {
            exit(0);
        }
    }

    std::cout << programStream << std::endl;
}
