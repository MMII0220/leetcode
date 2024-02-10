#include <iostream>

// Определение структуры для узла бинарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Функция для вставки элемента в бинарное дерево поиска
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Функция для вывода элементов дерева в порядке возрастания (ин-порядке обхода)
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    // Создание пустого бинарного дерева
    TreeNode* root = nullptr;

    // Вставка элементов в дерево
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 4);

    // Вывод элементов дерева в порядке возрастания
    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);

    return 0;
}
