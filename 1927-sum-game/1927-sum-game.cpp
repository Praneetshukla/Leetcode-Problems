#include <string>

class Solution {
public:
    bool sumGame(std::string num) {
        int n = num.size();
        int mid = n / 2;
        
        int s1 = 0, s2 = 0;
        int q1 = 0, q2 = 0;
        
        for (int i = 0; i < mid; ++i) {
            if (num[i] == '?') {
                q1++;
            } else {
                s1 += num[i] - '0';
            }
        }
        
        for (int i = mid; i < n; ++i) {
            if (num[i] == '?') {
                q2++;
            } else {
                s2 += num[i] - '0';
            }
        }
        
        // Alice wins if Bob cannot force equality
        return 2 * (s1 - s2) != 9 * (q2 - q1);
    }
};