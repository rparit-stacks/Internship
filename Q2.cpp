// Given a string, find the length of the longest substring without repeating
// characters.The function should return an integer representing the length of
// the longest substring without repeating characters.

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestSubstring(string str) {
    int maxLength = 0;
    vector<int> charIndex(128, -1);
    int left = 0;

    for (int right = 0; right < str.length(); right++) {
        if (charIndex[str[right]] >= left) {
            left = charIndex[str[right]] + 1;
        }
        charIndex[str[right]] = right;
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    string str = "ROHITPARIT";
    cout << longestSubstring(str);
    return 0;
}
