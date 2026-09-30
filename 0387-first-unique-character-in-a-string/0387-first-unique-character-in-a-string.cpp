class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        queue<int> q;

        for(int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            q.push(i);
        }

        while(!q.empty()) {
            int i = q.front();

            if(freq[s[i] - 'a'] == 1) {
                return i;
            }

            q.pop();
        }

        return -1;
    }
};