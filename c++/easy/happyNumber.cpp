#include <iostream>
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;

        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = calculateSumOfSquares(n);
        }

        return n == 1;
    }

private:
    int calculateSumOfSquares(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }
};

int main() {
    Solution solution;

    // Example 1
    int n1 = 19;
    std::cout << "Output 1: " << std::boolalpha << solution.isHappy(n1) << std::endl;

    // Example 2
    int n2 = 2;
    std::cout << "Output 2: " << std::boolalpha << solution.isHappy(n2) << std::endl;

    return 0;
}
