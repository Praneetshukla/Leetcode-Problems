class Solution {
public:
    string minWindow(string s, string t) {
        // Base case
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // Use size 128 to cover all uppercase and lowercase ASCII characters
        vector<int> map(128, 0);
        for (char c : t) {
            map[c]++;
        }

        int left = 0, right = 0;
        int required_chars = t.length(); 
        int min_len = INT_MAX;
        int start_index = 0;

        while (right < s.length()) {
            // If the character at the right pointer is in t, decrease our required count
            if (map[s[right]] > 0) {
                required_chars--;
            }
            // Decrease the frequency in the map and move right pointer
            map[s[right]]--;
            right++;

            // When required_chars == 0, we have a valid window containing all characters of t
            while (required_chars == 0) {
                // Update minimum window tracking
                if (right - left < min_len) {
                    min_len = right - left;
                    start_index = left;
                }

                // Now try to shrink the window from the left
                map[s[left]]++;
                // If removing the left character breaks our valid window, increment the required count
                if (map[s[left]] > 0) {
                    required_chars++;
                }
                left++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start_index, min_len);
    }
};