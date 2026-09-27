class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        unordered_map<char,int> mp;
        unordered_map<char,int> mp1;
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']++;
            mp1[t[i]-'a']++;
        }
        if(mp!=mp1) return false;
        return true;
    }
};