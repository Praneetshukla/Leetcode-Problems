class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    void subset(vector<int>& nums,int i){
        if(i==nums.size()){
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[i]);
        subset(nums,i+1);
        temp.pop_back();
        subset(nums,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        subset(nums,0);
        return ans;
    }
};