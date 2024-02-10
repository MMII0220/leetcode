#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, they are the same
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // If one of the nodes is null and the other is not, they are different
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // Check if the values are the same and recursively check left and right subtrees
        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

int main() {
    // Example 1
    TreeNode* p1 = new TreeNode(1);
    p1->left = new TreeNode(2);
    p1->right = new TreeNode(3);

    TreeNode* q1 = new TreeNode(1);
    q1->left = new TreeNode(2);
    q1->right = new TreeNode(3);

    Solution solution1;
    std::cout << std::boolalpha << "Output 1: " << solution1.isSameTree(p1, q1) << std::endl;

    // Example 2
    TreeNode* p2 = new TreeNode(1);
    p2->left = new TreeNode(2);

    TreeNode* q2 = new TreeNode(1);
    q2->right = new TreeNode(2);

    Solution solution2;
    std::cout << std::boolalpha << "Output 2: " << solution2.isSameTree(p2, q2) << std::endl;

    // Example 3
    TreeNode* p3 = new TreeNode(1);
    p3->left = new TreeNode(2);
    p3->right = new TreeNode(1);

    TreeNode* q3 = new TreeNode(1);
    q3->left = new TreeNode(1);
    q3->right = new TreeNode(2);

    Solution solution3;
    std::cout << std::boolalpha << "Output 3: " << solution3.isSameTree(p3, q3) << std::endl;

    return 0;
}
