#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> result(rowIndex + 1, 1);

        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j) {
                result[j] += result[j - 1];
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Example 1
    int rowIndex1 = 3;
    std::vector<int> result1 = solution.getRow(rowIndex1);
    std::cout << "Output 1: [";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;

    // Example 2
    int rowIndex2 = 0;
    std::vector<int> result2 = solution.getRow(rowIndex2);
    std::cout << "Output 2: [";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;

    // Example 3
    int rowIndex3 = 1;
    std::vector<int> result3 = solution.getRow(rowIndex3);
    std::cout << "Output 3: [";
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}
