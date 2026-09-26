class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0 ;
        int l=0;
        int len = 0; 
        for(int r=0;r<nums.size();r++){
            if(nums[r]==0 ){
                count++;
            }
            
                while(count>1){
                    if(nums[l]==0){
                        count--;
                    }
                    l++;
                }
            
            len = max(len,r-l+1);
        }
        return len-1;
    }
};