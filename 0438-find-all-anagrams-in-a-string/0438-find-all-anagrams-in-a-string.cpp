
class Solution {
public:
    vector<int> findAnagrams(string s, string p) { // check note too
        int n = s.size(), m = p.size();
        vector<int> ans;
        if(n < m) return ans;

        // Store character frequencies of s and p
        unordered_map<char,int> smap, pmap;
        for(char ch : p)
            pmap[ch]++;

        int count = 0; // Number of required characters matched

        // Build first window of size m
        int left = 0, right = 0;
        while(right < m) {
            char r = s[right];
            smap[r]++;

            // Count only required occurrences
            if(pmap[r] > 0 && smap[r] <= pmap[r])
                count++;

            right++;
        }

        // Valid anagram window
        if(count == m)
            ans.push_back(left);

        // Slide: remove left, add right
        while(right < n) {

            // Remove left character
            char l = s[left];

            // Decrease count only if it was contributing
            if(pmap[l] > 0 && smap[l] <= pmap[l])
                count--;

            smap[l]--;
            left++;

            // Add right character
            char r = s[right];
            smap[r]++;

            // Count only required occurrences
            if(pmap[r] > 0 && smap[r] <= pmap[r])
                count++;

            // Valid anagram window
            if(count == m)
                ans.push_back(left);

            right++;
        }

        return ans;
    }
};
