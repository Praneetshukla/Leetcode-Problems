#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string shortestBeautifulSubstring(std::string s, int k) {
        std::vector<int> ones;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }

        if (ones.size() < k) return "";

        // Step 1: Find the shortest candidate window length
        int min_len = s.size() + 1;
        for (int i = 0; i + k - 1 < ones.size(); ++i) {
            int len = ones[i + k - 1] - ones[i] + 1;
            min_len = std::min(min_len, len);
        }

        // Step 2: Compare only substrings of length min_len
        std::string ans = "";
        for (int i = 0; i + k - 1 < ones.size(); ++i) {
            int len = ones[i + k - 1] - ones[i] + 1;
            if (len == min_len) {
                std::string sub = s.substr(ones[i], len);
                if (ans.empty() || sub < ans) {
                    ans = sub;
                }
            }
        }

        return ans;
    }
};