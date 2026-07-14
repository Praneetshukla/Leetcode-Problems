class Solution {
public:
    vector<int> temp;
    int sum=0;
    void subset(vector<int>& nums,int i){
        if(i==nums.size()){
            int ans=0;
            for(int j : temp){
                ans^=j;
            }
            sum+=ans;
            return ;
        }
        temp.push_back(nums[i]);
        subset(nums,i+1);
        temp.pop_back();
        subset(nums,i+1);
        
    }
    int subsetXORSum(vector<int>& nums) {
        subset(nums,0);
        return sum;
    }
};