#include <iostream>
#include <vector>
#include <stack>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> nodeStack;

        while (root != nullptr || !nodeStack.empty()) {
            while (root != nullptr) {
                nodeStack.push(root);
                root = root->left;
            }

            root = nodeStack.top();
            nodeStack.pop();
            result.push_back(root->val);

            root = root->right;
        }

        return result;
    }
};

int main() {
    // Example 1
    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->left = new TreeNode(3);

    Solution solution1;
    std::vector<int> result1 = solution1.inorderTraversal(root1);
    for (int val : result1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Example 2
    TreeNode* root2 = nullptr;

    Solution solution2;
    std::vector<int> result2 = solution2.inorderTraversal(root2);
    for (int val : result2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Example 3
    TreeNode* root3 = new TreeNode(1);

    Solution solution3;
    std::vector<int> result3 = solution3.inorderTraversal(root3);
    for (int val : result3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
