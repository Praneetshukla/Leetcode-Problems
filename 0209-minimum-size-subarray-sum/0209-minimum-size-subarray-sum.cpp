class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l =0;
        int sum = 0;
        int len = INT_MAX;
        for(int r= 0 ; r<nums.size();r++){
            sum+=nums[r]; 
            while(sum>=target){
                int size = r-l+1;
                len = min(len,size);
                sum-=nums[l++];
            }
        }
        return len==INT_MAX?0:len;
    }
};