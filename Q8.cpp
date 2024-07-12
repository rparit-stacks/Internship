// Write a function to find the greatest common divisor (GCD) of two numbers.
// The function should return the GCD of a and b.

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int greatestCommonDivisor(int a, int b) {
    int res = 1;
    for (int i = 2; i <= min(a, b); i++) {
        if (a % i == 0 && b % i == 0)
            res = i;
    }

    return res;
}

int main() {
    int a, b;
    cout << "Enter Number 1 and Number 2 followed by space : " << endl;
    cin >> a >> b;
    cout << greatestCommonDivisor(a, b);
    return 0;
}