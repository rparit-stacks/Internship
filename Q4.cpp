// Design an algorithm to serialize and deserialize a binary tree. Serialization
// is the process of converting a data structure or object into a sequence of
// bits so that it can be stored in a file or memory buffer, or transmitted
// across a network connection link to be reconstructed later in the same or
// another computer environment. Implement the serialize and deserialize
// methods.

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

// Example usage
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
