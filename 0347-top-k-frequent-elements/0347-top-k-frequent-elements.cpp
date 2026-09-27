class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count the frequency of each number
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        
        // Step 2: Create buckets where the index is the frequency.
        // The maximum possible frequency is nums.size() (if all elements are the same).
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& pair : mp) {
            int number = pair.first;
            int frequency = pair.second;
            buckets[frequency].push_back(number);
        }
        
        // Step 3: Gather the top k frequent elements by reading the buckets from right to left
        vector<int> ans;
        for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; i--) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                // As soon as we have k elements, we can stop and return
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        
        return ans;
    }
};