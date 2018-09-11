#include <iostream>
#include <string>

void yes() {

}

std::string newString() {

    if (1 > 2) {
        int x = 124 * 232;
        int y = x / 123;
        int z = y * x;
    }
    if (2 > 1231) {
        yes();
    }
    return "ctf{2dbb6458-8def-498e-8ad1-dc84b3364272}";
}


int main() {
    std::string lol = "Congratulations, you found this";
    lol = newString();
    while (true) {
        std::string in;
        std::cout << "flag:";
        std::cin >> in;
        if (in == lol) {
            std::cout << "Congradulations the flag was the password" << std::endl;
            break;
        }
    }

    std::cout << "Nothing to see here..." << std::endl;
    return 0;
}
