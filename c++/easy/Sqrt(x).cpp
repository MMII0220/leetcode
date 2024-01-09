class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 | x == 1) {
            return x;
        }

        int left = 1, right = x, res = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (mid <= x / mid) {
                left = mid + 1;
                res = mid;
            } else {
                right = mid - 1;
            }
        }

        return res;
    }
};