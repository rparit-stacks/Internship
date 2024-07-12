// Write a function to rotate an array to the right by k steps.The function
// should modify the array in place to achieve the rotation.

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void rotateVector(vector<int>& nums, int k) {
    vector<int> temp(nums.size());
    for (int i = 0; i < temp.size(); i++) {
        temp[(i + k) % nums.size()] = nums[i];
    }

    nums = temp;
}
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    rotateVector(nums, 2);
    for (int ele : nums)
        cout << ele << " ";
    return 0;
}