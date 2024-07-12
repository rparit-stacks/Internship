
## Q1. Write a function to reverse a singly linked list.The function should take the head of the list and return the new head of the reversed list.

```
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {
    }
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr != NULL) {
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
```
![1](https://github.com/user-attachments/assets/67a34f95-3b39-4632-89bb-a5fe9a02e5ad)






## Q2. Given a string, find the length of the longest substring without repeatingcharacters.The function should return an integer representing the length of the longest substring without repeating characters.
```
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
```
![2](https://github.com/user-attachments/assets/356880ee-540b-490a-a9ab-2768ababd73e)


## Q3. Given a string, find the length of the longest substring without repeatingcharacters.The function should return an integer representing the length ofthe longest substring without repeating characters.
```
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
```
![3](https://github.com/user-attachments/assets/0523f360-66aa-4af0-934a-e6b5a4f1ab5d)


## Q4.Design an algorithm to serialize and deserialize a binary tree. Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment. Implement the serialize and deserialize methods.

```
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
};

class Codec {
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }

private:
    void serializeHelper(TreeNode* root, ostringstream& out) {
        if (!root) {
            out << "null ";
            return;
        }
        out << root->val << " ";
        serializeHelper(root->left, out);
        serializeHelper(root->right, out);
    }

    TreeNode* deserializeHelper(istringstream& in) {
        string token;
        in >> token;
        if (token == "null") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(token));
        root->left = deserializeHelper(in);
        root->right = deserializeHelper(in);
        return root;
    }
};

void printTree(TreeNode* root) {
    if (!root)
        return;
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    string serialized = codec.serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    TreeNode* deserialized = codec.deserialize(serialized);

    cout << "Deserialized tree: ";
    printTree(deserialized);
    cout << endl;

    return 0;
}
```
![4](https://github.com/user-attachments/assets/9addc9b6-51fa-4abe-abc7-02e16e4c74c0)


## Q5. Write a function to rotate an array to the right by k steps.The function should modify the array in place to achieve the rotation.
```
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
```
![5](https://github.com/user-attachments/assets/20a261a9-3a6f-4799-93af-fbfd71450007)


## Q6 Write a function to find the factorial of a given number.The function should return the factorial of the number.
```
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
```
![6](https://github.com/user-attachments/assets/74d4f140-73f0-498d-9109-81a0e304d826)


## Q7. Write a function to compute the sum of the digits of a given number.The function should return the sum of the digits of the number.
```
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
```
![7](https://github.com/user-attachments/assets/18ddc0c6-bb15-4500-bd37-5422317de993)


## Q8 Write a function to find the greatest common divisor (GCD) of two numbers. The function should return the GCD of a and b.
```
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
```
![8](https://github.com/user-attachments/assets/7c0932f8-6f46-4149-89e5-476827129323)


## Q9. Write a function to find the maximum difference between any two elements in an array.The function should return the maximum difference between any two elements in the array.
```
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
```

![9](https://github.com/user-attachments/assets/55363942-c528-4746-8344-ccb99ef69337)


## 10. Write a function to check if a given string contains only alphabetic characters.The function should return true if the string contains only alphabetic characters, and false otherwise.
```
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
```
![10](https://github.com/user-attachments/assets/93eea6ac-117e-4b12-b2c7-3fca8fac9eee)
