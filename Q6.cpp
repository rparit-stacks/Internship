// Write a function to find the factorial of a given number.The function should
// return the factorial of the number.

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int findFactorial(int num) {
    if (num == 1)
        return 1;
    else
        return num * findFactorial(num - 1);
}

int main() {
    int num = 5;
    cout << findFactorial(5);
    return 0;
}