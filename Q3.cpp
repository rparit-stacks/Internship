// Given a non-empty binary tree, find the maximum path sum. A path is defined
// as any sequence of nodes from some starting node to any node in the tree
// along the parent-child connections. The path must contain at least one node
// and does not need to go through the root.The function should return an
// integer representing the maximum path sum.

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
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

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        maxPathSumHelper(root, maxPathSum);
        return maxPathSum;
    }

    int maxPathSumHelper(TreeNode* node, int& maxPathSum) {
        if (node == nullptr)
            return 0;

        int leftSum = max(0, maxPathSumHelper(node->left, maxPathSum));
        int rightSum = max(0, maxPathSumHelper(node->right, maxPathSum));
        int nodeMaxPathSum = node->val + leftSum + rightSum;

        maxPathSum = max(maxPathSum, nodeMaxPathSum);

        return node->val + max(leftSum, rightSum);
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution solution;
    TreeNode* root = createSampleTree();
    int result = solution.maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl;
    return 0;
}
