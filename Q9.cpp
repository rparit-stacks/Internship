// Write a function to find the maximum difference between any two elements in
// an array.The function should return the maximum difference between any two
// elements in the array.

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int maximumDifference(vector<int>& nums) {
    // we will sort this array first
    sort(nums.begin(), nums.end());

    // the maximum difference will be the biggest - smallest
    return nums[nums.size() - 1] - nums[0];
}
int main() {
    vector<int> nums = {1, 7, 8, 45, 9, 6, 5, 8, 7, 4, 2, 5, 7, 85, 69};

    cout << maximumDifference(nums);

    return 0;
}