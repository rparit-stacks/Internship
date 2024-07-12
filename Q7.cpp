// Write a function to compute the sum of the digits of a given number.The
// function should return the sum of the digits of the number.

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int sumOfNumber(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int num = 98101676;
    cout << sumOfNumber(num);

    return 0;
}