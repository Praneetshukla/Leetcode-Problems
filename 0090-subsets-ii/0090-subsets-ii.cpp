class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int>& nums, int start) {
        ans.push_back(path);

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicates at the same level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
};