class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, unsigned> romanint = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (romanint[s[i]] < romanint[s[i+1]]) {
                ans -= romanint[s[i]];
            } else {
                ans += romanint[s[i]];
            }
        }

        return ans;
    }
};

// beats 58%
// beats 59% in memory
