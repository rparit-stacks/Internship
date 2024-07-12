// Write a function to check if a given string contains only alphabetic
// characters.The function should return true if the string contains only
// alphabetic characters, and false otherwise.

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkForalphabetic(string str) {
    for (char c : str) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
            return false;
    }
    return true;
}
int main() {
    string str = "MyNameIsRohitParit";
    cout << checkForalphabetic(str);
    return 0;
}