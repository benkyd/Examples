#include <iostream>
using namespace std;

long factorial(int num) {
    long factor = num;
    for (int i = 1; i < num; i++) {
        factor = i * factor;
    }
    return factor;
}

int main() {
    int num;
    cout << "Enter a number to find it's factorial: ";
    cin >> num;

    long output = factorial(num);
    cout << output;

    cin >> num;
    return 0;
}